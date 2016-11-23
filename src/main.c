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
  luhn_opts opts;
  int retval = 0;

  apr_initialize();
  apr_pool_create(&mp, NULL);

  retval = parse_opts (&mp, &opts, argc, argv);

  // Validate number
  if (opts.validate == true) {
    if ((retval = luhn_valid (opts.number)) == 0) {
      verb_print ("OK: valid Luhn number\n");
    } else {
      verb_print ("FAIL: invalid Luhn number\n");
    }
  }

  // Generate number
  if (retval == 0 && opts.generate == true) {
    printf ("%s\n", luhn_gen (mp, opts.len));
  }

  apr_pool_destroy(mp);
  apr_terminate();
  return retval;
}

