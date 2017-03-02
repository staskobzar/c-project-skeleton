#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([luhn], [1.0], [staskobzar@gmail.com])
AM_INIT_AUTOMAKE([foreign parallel-tests color-tests -Wall -Werror])
AC_PROG_RANLIB
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
# ISO standard C99
AC_PROG_CC_STDC
AM_PROG_CC_C_O

### Checks for libraries.

# Doxygen
AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])

# check for APR
AC_SEARCH_LIBS(apr_initialize, [apr-1], [],
        [AC_MSG_ERROR([Apache Portable Runtime lib not installed. Install libapr-1.])])
PKG_CHECK_MODULES([APR], [apr-1], [have_cmocka="yes"])

# check cmocka
PKG_CHECK_EXISTS(cmocka >= 1.0.0,
        [AC_CHECK_HEADERS([stdarg.h stddef.h setjmp.h],
            [], dnl We are only intrested in action-if-not-found
            [AC_MSG_WARN([Header files stdarg.h stddef.h setjmp.h are required by cmocka])
             cmocka_required_headers="no"
            ]
        )
        AS_IF([test x"$cmocka_required_headers" != x"no"],
              [PKG_CHECK_MODULES([CMOCKA], [cmocka], [have_cmocka="yes"])]
        )],
        dnl PKG_CHECK_EXISTS ACTION-IF-NOT-FOUND
        [AC_MSG_WARN([No libcmocka-1.0.0 or newer library found, cmocka tests will not be built])]
    )
AM_CONDITIONAL([HAVE_CMOCKA], [test x$have_cmocka = xyes])

# Test coverage generate. Flag: --with-coverage
AC_ARG_WITH([coverage],
            AS_HELP_STRING([--with-coverage], [Generate test covearge report with lcov.]),
            [with_cov=true], []
            )
AM_CONDITIONAL([WITH_COVERAGE], [test x$with_cov = xtrue])
if test x$with_cov = xtrue; then
  AC_PATH_PROG(LCOV, lcov)
  AC_PATH_PROG(GCOV, gcov)
  AC_PATH_PROG(GENHTML, genhtml)
  COVERAGE_CFLAGS="--coverage"
  COVERAGE_OPTFLAGS="-O0"
  AC_SUBST([GCOV])
  AC_SUBST([LCOV])
  AC_SUBST([GENHTML])
  AC_SUBST([COVERAGE_CFLAGS])
  AC_SUBST([COVERAGE_OPTFLAGS])
fi
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AM_PROG_AR
AC_CONFIG_FILES([Makefile
                 doc/Doxyfile
                 doc/Makefile
                 src/Makefile
                 src/lib/Makefile
                 test/Makefile])

AC_OUTPUT
