#include <criterion/criterion.h>

int my_atoi(const char *str);

TestSuite(my_atoi, .timeout = 15);

Test(my_atoi, zero)
{
    cr_assert_eq(my_atoi("0"), 0);
}

Test(my_atoi, simple)
{
    cr_assert_eq(my_atoi("124"), 124);
}

Test(my_atoi, int_max)
{
    cr_assert_eq(my_atoi("2147483647"), 2147483647);
}

Test(my_atoi, int_min)
{
    cr_assert_eq(my_atoi("-2147483648"), -2147483648);
}

Test(my_atoi, negative_simple)
{
    cr_assert_eq(my_atoi("-1"), -1);
}

Test(my_atoi, negative_more)
{
    cr_assert_eq(my_atoi("-54789"), -54789);
}

Test(my_atoi, forty_two)
{
    cr_assert_eq(my_atoi("42"), 42);
}

Test(my_atoi, spaces)
{
    cr_assert_eq(my_atoi("     42"), 42);
}

Test(my_atoi, spaces_again)
{
    cr_assert_eq(my_atoi("     45678     "), 0);
}

Test(my_atoi, two_sequences)
{
    cr_assert_eq(my_atoi("     4278     5689   "), 0);
}

Test(my_atoi, spaces_and_negative)
{
    cr_assert_eq(my_atoi("     -4211     "), 0);
}

Test(my_atoi, invalid)
{
    cr_assert_eq(my_atoi("abcd42"), 0);
}

Test(my_atoi, invalid_and_spaces)
{
    cr_assert_eq(my_atoi("   fezfez42"), 0);
}

Test(my_atoi, invalid_complex)
{
    cr_assert_eq(my_atoi("-42456jeajea45"), 0);
}

Test(my_atoi, plus)
{
    cr_assert_eq(my_atoi("+12346"), 12346);
}

Test(my_atoi, plus_and_spaces)
{
    cr_assert_eq(my_atoi("   +126"), 126);
}

Test(my_atoi, several_signs)
{
    cr_assert_eq(my_atoi("+--7856"), 0);
}

Test(my_atoi, space_between_sign_and_number)
{
    cr_assert_eq(my_atoi("+ 126"), 0);
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
