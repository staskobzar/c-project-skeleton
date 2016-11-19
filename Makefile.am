SUBDIRS = src test doc
CTAGSFLAGS= -R src

if WITH_COVERAGE
COV_INFO_FILE = $(top_builddir)/coverage.info
COV_DIR = $(top_builddir)/coverage
cov:
	$(MAKE) $(AM_MAKEFLAGS) \
		CFLAGS="$(CFLAGS) $(COVERAGE_CFLAGS) $(COVERAGE_OPTFLAGS)"
	$(MAKE) $(AM_MAKEFLAGS) check \
		CFLAGS="$(CFLAGS) $(COVERAGE_CFLAGS) $(COVERAGE_OPTFLAGS)"
	@echo "Generating coverage report..."
	$(LCOV) --capture \
		--directory "$(top_builddir)/src" \
		--output-file $(COV_INFO_FILE) \
		--gcov-tool $(GCOV)
	$(GENHTML) --prefix "$(top_builddir)" \
		--output-directory $(COV_DIR) \
		--title $(PACKAGE_NAME) \
		--legend --show-details \
		$(COV_INFO_FILE)

clean-local:
	@echo "Cleaning lcov files."
	@find $(top_builddir) -name "*.gcno" -exec rm -v {} \;
	@find $(top_builddir) -name "*.gcda" -exec rm -v {} \;
	@rm -rf $(top_builddir)/coverage*
endif

