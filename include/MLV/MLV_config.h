/*
 *   This file is part of the MLV Library.
 *
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

#ifndef __MLV_CONFIG_H__
#define __MLV_CONFIG_H__

#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    #define MLVDECL __declspec(dllexport)
    #define MLVIMPORT __declspec(dllimport)
#else
    #define MLVDECL
    #define MLVIMPORT
#endif

#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__)
    #define MLVCALL __cdecl
#else
    #define MLVCALL
#endif

#ifdef MLV_BUILD
    #define MLVAPI MLVDECL MLVCALL
#else
    #define MLVAPI MLVIMPORT MLVCALL
#endif

#endif // __MLV_CONFIG_H__