/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2012 Adrien Boussicault, Marc Zipstein
 *	 Copyright (C) 2025 OJddJO
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

#ifndef __MLV__KEY_H__
#define __MLV__KEY_H__

#include "MLV_config.h"

typedef struct _MLV_Key MLV_Key;

MLVAPI MLV_Key *MLV_create_key(void *value, void (*value_destroying_function)(void *value),
    int (*compare_values)(void *value1, void *value2));

MLVAPI void MLV_free_key(MLV_Key *key);

MLVAPI int MLV_compare_keys(MLV_Key *key1, MLV_Key *key2);

MLVAPI MLV_Key *MLV_string_to_key(const char *text);
MLVAPI MLV_Key *MLV_integer_to_key(int integer);

MLVAPI void *MLV_get_value_from_key(MLV_Key *key);

#endif
