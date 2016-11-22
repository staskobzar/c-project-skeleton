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
 * Maximum Luhn number length.
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
 * @param num  String that represents number
 * @param size Length of number to generate
 * @return int size of number
 */
int luhn_gen (char *num, int size);

#endif
