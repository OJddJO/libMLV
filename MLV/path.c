/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2011,2012 Adrien Boussicault, Marc Zipstein
 *   Copyright (C) 2025 OJddJO
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MLV_path.h"
#include "data_structure.h"
#include "memory_management.h"
#include "warning_error.h"

#include <dirent.h>
#include <stdarg.h>
#include <string.h>

#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    #include <fileapi.h>
#else
    #include <sys/stat.h>
    #include <unistd.h>
#endif

#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    #define MLV_IS_DIR_SEPARATOR(c) ((c) == '/' || (c) == '\\')
    #define MLV_DIR_SEPARATOR_CHAR  '\\'
    #define MLV_DIR_SEPARATOR       "\\"
#else
    #define MLV_IS_DIR_SEPARATOR(c) ((c) == '/')
    #define MLV_DIR_SEPARATOR_CHAR  '/'
    #define MLV_DIR_SEPARATOR       "/"
#endif

MLVAPI char *MLV_get_base_name(const char *path) {
    // return g_path_get_basename( path );

    if (!path) return NULL;

    long len = strlen(path);
    if (len == 1) {
        if (MLV_IS_DIR_SEPARATOR(path[0])) return strdup(MLV_DIR_SEPARATOR);
        return strdup(".");
    }

    const char *end = path + len;
    const char *start = end - 1;
    while (start >= path && !MLV_IS_DIR_SEPARATOR(*start))
        start--;

    start++;

    long base_len = end - start;
    char *result = (char *)MLV_MALLOC(base_len + 1, char);
    memcpy(result, start, base_len);
    result[base_len] = '\0';

    return result;
}

MLVAPI char *MLV_get_directory_name(const char *path) {
    // return g_path_get_dirname( path );

    if (!path) return NULL;

    long len = strlen(path);

    while (len > 0 && MLV_IS_DIR_SEPARATOR(path[len - 1]))
        len--;

    if (len == 0) return strdup(".");

    char *result = (char *)MLV_MALLOC(len + 1, char);
    memcpy(result, path, len);
    result[len] = '\0';

    return result;
}

MLVAPI int MLV_path_is_absolute(const char *path) {
    // return g_path_is_absolute( path );
    if (path == NULL) return 0;

#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    if (strlen(path) == 3 && ((path[0] >= 'a' && path[0] <= 'z') || (path[0] >= 'A' && path[0] <= 'Z')) &&
        path[1] == ':' && MLV_IS_DIR_SEPARATOR(path[2])) {
        return 1;
    }
#else
    if (MLV_IS_DIR_SEPARATOR(path[0])) return 1;
#endif

    return 0;
}

MLVAPI int MLV_path_is_relative(const char *path) {
    return !MLV_path_is_absolute(path);
}

MLVAPI char *MLV_build_path_v(char **elements) {
    // gchar* tmp_res = g_build_filenamev( elements );
    // char* result = strdup( tmp_res );
    // g_free( tmp_res ); // tmp_res have to be freed with g_free (
    //                    //     see glib documentation
    //                    // )

    if (!*elements) return NULL;

    long len = strlen(*elements);
    char *result = (char *)MLV_MALLOC(len + 2, char);
    memcpy(result, *elements, len);

    while (*(++elements)) {
        if (!MLV_IS_DIR_SEPARATOR(result[len - 1])) {
            result[len] = MLV_DIR_SEPARATOR_CHAR;
            len++;
        }
        long elemLen = strlen(*elements);
        char *newRes = (char *)MLV_REALLOC(result, len + elemLen + 1, char);
        if (!newRes) return NULL;
        result = newRes;
        memcpy(result + len, *elements, elemLen);
        len += elemLen;
    }

    result[len] = '\\';
    result[len + 1] = '\0';
    return result;
}

MLVAPI char *MLV_build_path(const char *first_element, ...) {
    char *result;

    if (!first_element) return NULL;

    va_list pile;
    const char *type;
    int compteur;

    va_start(pile, first_element);
    compteur = 2;
    while ((type = va_arg(pile, char *)) != NULL) {
        compteur++;
    }
    va_end(pile);

    char **elements = MLV_MALLOC(compteur, char *);
    elements[0] = strdup(first_element);

    va_start(pile, first_element);
    int i;
    for (i = 1; i < compteur; i++) {
        type = va_arg(pile, const char *);
        if (type) {
            elements[i] = strdup((const char *)type);
        } else {
            elements[i] = NULL;
        }
    }
    va_end(pile);

    result = MLV_build_path_v(elements);

    for (i = 0; i < compteur - 1; i++) {
        MLV_FREE(elements[i], char);
    }
    MLV_FREE(elements, char *);
    return result;
}

MLVAPI int MLV_path_is_a_directory(const char *path) {
    if (!path) return 0;
    DIR *dir = opendir(path);
    if (dir) closedir(dir);
    return dir != NULL;
}

MLVAPI int MLV_path_is_a_file(const char *path) {
    if (!path) return 0;
    DIR *dir = opendir(path);
    if (dir) {
        closedir(dir);
        return 0;
    }
    FILE *file = fopen(path, "r");
    if (file) fclose(file);
    return file != NULL;
}

MLVAPI int MLV_path_exists(const char *path) {
    if (!path) return 0;
    FILE *file = fopen(path, "r");
    if (file) fclose(file);
    return file != NULL;
}

MLVAPI char *MLV_get_current_directory() {
#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    return _getcwd(NULL, 0);
#else
    return getcwd(NULL, 0);
#endif
}

MLVAPI const char *MLV_get_temporary_directory() {
#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    DWORD size = GetTempPathA(0, NULL) + 1;
    LPSTR path = (LPSTR)MLV_MALLOC(size, CHAR);
    if (!GetTempPathA(size, path)) {
        MLV_FREE(path, CHAR);
        return NULL;
    }
    return (char *)path;
#else
    return strdup("/tmp");
#endif
}

MLVAPI const char *MLV_get_home_directory() {
#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    char *path = getenv("HOMEPATH");
#else
    char *path = getenv("HOME");
#endif
    if (!path) return NULL;
    return strdup(path);
}
