#include <criterion/criterion.h>

void array_max_min(int tab[], size_t len, int *max, int *min);

TestSuite(array_max_min, .timeout = 15);

Test(array_max_min, test_00)
{
    int max = 0;
    int min = 0;
    int tab[] = { 5, 1, 30, 0, 20, 100 };
    size_t len = 6;
    array_max_min(tab, len, &max, &min);
    cr_assert_eq(max, 100);
    cr_assert_eq(min, 0);
}

Test(array_max_min, test_01)
{
    int max = 0;
    int min = 0;
    int tab[] = { -5, -1, -30, 0, -20, -100 };
    size_t len = 6;
    array_max_min(tab, len, &max, &min);
    cr_assert_eq(max, 0);
    cr_assert_eq(min, -100);
}

Test(array_max_min, test_02)
{
    int max = 0;
    int min = 0;
    int tab[] = { 0, 0 };
    size_t len = 2;
    array_max_min(tab, len, &max, &min);
    cr_assert_eq(max, 0);
    cr_assert_eq(min, 0);
}

Test(array_max_min, test_03)
{
    int max = 0;
    int min = 0;
    int tab[] = { 10 };
    size_t len = 1;
    array_max_min(tab, len, &max, &min);
    cr_assert_eq(max, 10);
    cr_assert_eq(min, 10);
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
