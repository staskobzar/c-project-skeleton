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
 * @file util.c
 * @brief Utility functions implementation
 *
 * @author Stas Kobzar <staskobzar@gmail.com>
 */
#include "util.h"
#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <apr_getopt.h>
#include <apr_strings.h>

/**
 * Application options list
 */
static const apr_getopt_option_t optset[] = {
  { "help",     'h',  FALSE,  "Prints out a simple usage help message." },
  { "check",    'c',  TRUE,   "Validate if given number is a Luhn number." },
  { "generate", 'g',  FALSE,  "Generate Luhn valid number. Default length is 16 digits." },
  { "length",   'l',  TRUE,   "Length of the number to generate. Valid value is between 4 and 1024." },
  { "verbose",  'v',  FALSE,  "Enable verbose output." },
  { "version",  'V',  FALSE,   "Print version and exit." },
  { NULL, 0, 0, NULL },
};

apr_status_t parse_opts (apr_pool_t **mp,
                         luhn_opts *luhnopts,
                         int argc,
                         const char *argv[])
{
  int retval = 0;
  apr_status_t rv;
  apr_getopt_t *opt;
  int optch;
  const char *optarg;
  char *endptr;

  init_opts (luhnopts);

  // no arguments, print help
  if (argc < 2) {
    usage ();
    return retval;
  }

  apr_getopt_init(&opt, *mp, argc, argv);
  while ((rv = apr_getopt_long(opt, optset, &optch, &optarg)) == APR_SUCCESS) {
    switch (optch) {
      case 'h':
        usage ();
        break;
      case 'V':
        copyright ();
        break;
      case 'v':
        verb_init (true);
        break;
      case 'l':
        luhnopts->len = strtol(optarg, &endptr, 10);
        if (luhnopts->len < MIN_LEN || luhnopts->len > MAX_LEN) {
          printf("FAIL: length must be beween 4 and 1024\n");
          retval = 10;
        }
        break;
      case 'g':
        luhnopts->generate = true;
        break;
      case 'c':
        apr_cpystrn(luhnopts->number, optarg, MAX_LEN);
        luhnopts->validate = true;
        break;
      default:
        break;
    }
  }
  if (rv != APR_EOF) {
    printf("Invalid parameter. Try --help.\n");
    retval = 11;
  }
  return retval;
}

void init_opts (luhn_opts *opts)
{
  opts->validate = false;
  opts->generate = false;
  opts->len = DEFAULT_LEN;
}

void verb_init (bool verbose_flag)
{
  verbose = verbose_flag;
}

void verb_print (const char *msg)
{
  if (verbose == true)
    printf("%s", msg);
}

void usage ()
{
  const apr_getopt_option_t *opts = optset;
  printf("Usage: " PACKAGE " [OPTION]...\n");
  printf("Check and generate Luhn numbers.\n");
  printf("\n");
  printf("Mandatory arguments to long options are mandatory for short options too.\n");
  printf("\n");
  printf("Options:\n");
  while (opts->optch != 0) {
    printf("  -%c, --%s ", opts->optch, opts->name);
    if (opts->has_arg) printf("[VALUE]");
    printf("\n");
    printf("        %s\n", opts->description);
    opts++;
  }

  printf("\n");
  copyright();
}

void copyright()
{
  printf( PACKAGE_STRING " Copyright (C) 2016  " PACKAGE_BUGREPORT "\n"
          "This program comes with ABSOLUTELY NO WARRANTY.\n"
          "This is free software, and you are welcome to redistribute it\n"
          "under conditions describer in COPYRIGHT file.\n");
}

