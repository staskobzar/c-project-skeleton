/**
 * luhn -- Tool to verify and generate Luhn numbers
 * Copyright (C) 2016, Stas Kobzar <stas@modulis.ca>
 *
 * This file is part of luhn.
 *
 * skinnycat is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * skinnycat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with luhn.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file luhn.h
 * @brief Ligrary that contains API for verify and generate functions.
 *
 * @author Stas Kobzar <staskobzar@gmail.com>
 */
#ifndef __LUHN_H
#define __LUHN_H

#include <apr.h>
#include <apr_general.h>

/*
 * Minimum Luhn number length 4 digits.
 * Actually, the smallest Luhn number is 0.
 * This is just this tool limit.
 */
#define MIN_LEN 4
/*
 * Maximum Luhn number length 1024 digits.
 * Actually, it can be any length. It's just
 * this tool limit.
 */
#define MAX_LEN 1024

/**
 * Verify number with Luhn algorithm
 * @param number String that represents number
 * @return int 0 if number is valid
 */
int luhn_valid (const char *num);

/**
 * Generate valid Luhn number
 * @param mp   Memory pool
 * @param size Length of number to generate
 * @return  pointer to the Luhn number represented as string.
 *          If given size is less then MIN_LEN or greater then MAX_LEN
 *          then return NULL.
 */
char* luhn_gen (apr_pool_t *mp, int size);

#endif
