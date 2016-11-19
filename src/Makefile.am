SUBDIRS=lib

AM_CFLAGS = -Ilib

bin_PROGRAMS = luhn
luhn_SOURCES = main.c util.c util.h
luhn_CFLAGS = @APR_CFLAGS@ -I$(top_builddir)/src/lib
luhn_LDADD = -L$(top_builddir)/src/lib -lluhn @APR_LIBS@
