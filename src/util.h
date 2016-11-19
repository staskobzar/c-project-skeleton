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

/* enable verbosity */
static int verbose = 0;

/**
 * Initiate verbosity.
 * @param verbose_flag Verbosity flag to enable/disable
 * @return void
 */
void verb_init (int verbose_flag);

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

#endif
