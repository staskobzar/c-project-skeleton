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
 * @file main.c
 * @brief luhn tool main proc
 *
 * @author Stas Kobzar <staskobzar@gmail.com>
 */

#include <stdio.h>
#include "util.h"
#include "luhn.h"

/**
 * Luhn numbers main proc
 */
int main(int argc, const char *argv[])
{
  apr_pool_t *mp;
  char *num;

  apr_initialize();
  apr_pool_create(&mp, NULL);

  num = apr_palloc(mp, 12);
  luhn_gen (num, 12);
  printf("gen num: %s\n", num);
  apr_pool_destroy(mp);
  apr_terminate();
  return 0;
}

