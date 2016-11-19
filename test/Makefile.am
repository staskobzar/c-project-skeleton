AUTOMAKE_OPTIONS=dejagnu
DEJATOOL = frontend
RUNTESTFLAGS=LUHN=$(top_builddir)/src/luhn

if HAVE_CMOCKA
  TESTS = luhn_tests
  check_PROGRAMS = luhn_tests
  luhn_tests_SOURCES = luhn_tests.c
  luhn_tests_CFLAGS = @CMOCKA_CFLAGS@ -I$(top_builddir)/src/lib
  luhn_tests_LDADD = -L$(top_builddir)/src/lib -lluhn @CMOCKA_LIBS@
endif

