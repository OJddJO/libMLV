/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2010,2011,2012 Adrien Boussicault, Marc Zipstein
 *   Copyright (C) 2016 Eric Laporte (Bug on MLV_get_random_integer)
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

#include "MLV_random.h"

#ifndef MEMORY_DEBUG
    #include <SDL/SDL.h>
#else
    #include "memory_debug.h"
#endif

#include "memory_management.h"
#include "warning_error.h"

#include <stdlib.h>

MLVAPI void MLV_set_seed(int32_t seed) {
    srand((uint32_t)seed);
}

MLVAPI int MLV_get_random_boolean() {
    return rand() % 2;
}

inline static int rand_int() {
#if RAND_MAX == INT32_MAX
    return rand();
#else // minimum value of RAND_MAX is 32768=0x7FFF
    return (uint32_t)((rand() & 1) << 30 | (rand() & 0x7FFF) << 15 | (rand() & 0x7FFF));
#endif
}

MLVAPI int MLV_get_random_integer(int begin, int end) {
    return begin + rand_int() % (end - begin + 1);
}

MLVAPI double MLV_get_random_double(double begin, double end) {
    return begin + ((double)rand_int() / (double)(INT32_MAX)) * (end - begin);
}
