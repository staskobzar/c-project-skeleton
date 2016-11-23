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
 * @file util.h
 * @brief Utility functions declaration
 *
 * @author Stas Kobzar <staskobzar@gmail.com>
 */
#ifndef __UTIL_H
#define __UTIL_H

#include <apr.h>

#include "luhn.h"

typedef unsigned char bool;
#define false 0
#define true  (!false)

/* enable verbosity */
static bool verbose = 0;

/**
 * Structure to store configuration parameters.
 */
struct luhn_opts_s {
  bool validate;
  bool generate;
  char number[MAX_LEN];
  unsigned short len;
};

/**
 * @see luhn_opts_s
 */
typedef struct luhn_opts_s luhn_opts;

/**
 * Parse command line arguments.
 * @param mp    APR memory pool
 * @param opts  Options structure
 * @param argc  Number of argumets
 * @param argv  Array of arguments
 * @return 0 if parameters successfull
 */
int parse_opts (apr_pool_t **mp, luhn_opts *opts, int argc, const char *argv[]);

/**
 * Initialize configuration options structure.
 * @param luhn_opts
 */
void init_opts (luhn_opts *opts);

/**
 * Initiate verbosity.
 * @param verbose_flag Verbosity flag to enable/disable
 * @return void
 */
void verb_init (bool verbose_flag);

/**
 * Print message. Prints message is vebosity enabled.
 * @param msg Message to print
 * @return void
 */
void verb_print (const char *msg);

/**
 * Print usage message
 */
void usage (void);

/**
 * Print version and copyrights and exit.
 */
void copyright(void);

#endif
