#include <criterion/criterion.h>
#include <stddef.h>
#include <string.h>

size_t my_strspn(const char *s, const char *accept);

TestSuite(my_strspn, .timeout = 15);

Test(my_strspn, simple)
{
    const char *s = "string";
    const char *accept = "string";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, caps)
{
    const char *s = "string";
    const char *accept = "STRING";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, empty_one)
{
    const char *s = "";
    const char *accept = "STRING";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, empty_two)
{
    const char *s = "ABCD";
    const char *accept = "";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, digits_1)
{
    const char *s = "11111";
    const char *accept = "1234567890";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, digits_2)
{
    const char *s = "129th";
    const char *accept = "1234567890";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, digits_3)
{
    const char *s = "129th1298";
    const char *accept = "1234567890";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, split)
{
    const char *s = "ABCD\0EFGH";
    const char *accept = "AEFG";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, backslash)
{
    const char *s = "AB\nBBYOLO";
    const char *accept = "A2\n3B856";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

Test(my_strspn, mixed)
{
    const char *s = "1 WiL7 B3e b4cK";
    const char *accept = "12345ABCDabcd";
    cr_assert_eq(my_strspn(s, accept), strspn(s, accept));
}

int main(int argc, char *argv[])
{
    struct criterion_test_set *tests = criterion_initialize();

    int result = 0;
    if (criterion_handle_args(argc, argv, true))
        result = !criterion_run_all_tests(tests);

    criterion_finalize(tests);
    return result;
}
