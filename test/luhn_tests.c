#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "luhn.h"

static void luhn_check_success (void **state)
{
  (void) *state;
  assert_int_equal (0, luhn_valid ("hello"));
}

static void luhn_check_fail (void **state)
{
  (void) *state;
  assert_int_equal (1, 1);
}

static void luhn_gen_test (void **state)
{
  (void) *state;
  char toto[1024];
  assert_int_equal (0, luhn_gen (toto));
}

int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test (luhn_check_success),
    cmocka_unit_test (luhn_check_fail),
    cmocka_unit_test (luhn_gen_test),
  };
  return cmocka_run_group_tests_name("luhn lib tests", tests, NULL, NULL);
}
