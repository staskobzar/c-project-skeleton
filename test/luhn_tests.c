#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>

#include "luhn.h"

const char* valid_nums[] = {
  "4556224242479034",
  "3535297944875111",
  "372542317279595",
  "1234567812345670",
  "49927398716"
};

const char* invalid_nums[] = {
  "49927398717",
  "1234567812345678",
  "453992406665297",
  "5544850398429482",
  "5917375561450081"
};

/*
 * Setup and teardown for create message tests
 */
static int setup(void **state) {
  apr_pool_t *mp;

  apr_initialize();
  apr_pool_create(&mp, NULL);

  *state = mp;

  return 0;
}

static int teardown(void **state) {
  apr_pool_destroy(*state);
  apr_terminate();
  return 0;
}

static void luhn_check_success (void **state)
{
  (void) *state;
  int i;
  for (i = 0; i < (sizeof (valid_nums) / sizeof (char*)); i++) {
    assert_int_equal (0, luhn_valid (valid_nums[i]));
  }
}

static void luhn_check_fail (void **state)
{
  (void) *state;
  int i;
  for (i = 0; i < (sizeof (invalid_nums) / sizeof (char*)); i++) {
    assert_int_not_equal (0, luhn_valid (invalid_nums[i]));
  }
}

static void luhn_gen_test (void **state)
{
  int i;
  for (i = 0; i < 100; i++ ) {
    char *num = apr_palloc(*state, (i + 6) * 2);
    assert_int_equal (0, luhn_gen (num, (i + 6) * 2 ));
    assert_int_equal (0, luhn_valid (num));
  }
}

int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test (luhn_check_success),
    cmocka_unit_test (luhn_check_fail),
    cmocka_unit_test_setup_teardown (luhn_gen_test, setup, teardown),
  };
  return cmocka_run_group_tests_name("luhn lib tests", tests, NULL, NULL);
}
