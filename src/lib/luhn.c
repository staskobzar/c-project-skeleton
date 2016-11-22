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
 * @file luhn.c
 * @brief Ligrary that contains API for verify and generate functions.
 *
 * @author Stas Kobzar <staskobzar@gmail.com>
 */
#include "luhn.h"
#include <time.h>

/**
 * Taken from Rosetta Code
 * http://rosettacode.org/wiki/Luhn_test_of_credit_card_numbers#C
 */
int luhn_valid (const char *num)
{
  const int m[] = {0,2,4,6,8,1,3,5,7,9}; // mapping for rule 3
  int i, odd = 1, sum = 0;

  for (i = strlen(num); i--; odd = !odd) {
    int digit = num[i] - '0';
    sum += odd ? digit : m[digit];
  }

  return sum % 10;
}

char* luhn_gen (apr_pool_t *mp, int size)
{
  int i, digit, remainder;
  char *num;

  if (size < MIN_LEN || size > MAX_LEN)
    return NULL;

  num = (char*)apr_palloc(mp, size);

  srand((unsigned)time(NULL));

  for (i = 0; i < size; i++) {
    digit = rand() % 10;
    num[i] = digit + '0';
  }
  remainder = luhn_valid (num);
  if (remainder == 0)
    return num;
  num[size - 1] = (10 + digit - remainder) % 10 + '0';
  return num;
}

