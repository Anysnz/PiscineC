#include <criterion/criterion.h>
#include <stdlib.h>

static void assert_sort_eq(int *array, int *ref_array, size_t size)
{
    cr_assert(array != NULL,
              "Student should not be NULL on attempt to compare with ref");
    cr_assert(ref_array != NULL,
              "Ref should not be NULL on attempt to compare with student");

    for (size_t i = 0; i < size; ++i)
        cr_assert_eq(array[i], ref_array[i]);
}

int bubble_sort(int array[], size_t size);

TestSuite(bubble_sort, .timeout = 15);

Test(bubble_sort, empty)
{
    int *empty_array = malloc(0);
    int *expected = malloc(0);

    bubble_sort(empty_array, 0);
    assert_sort_eq(empty_array, expected, 0);

    free(empty_array);
    free(expected);
}

Test(bubble_sort, one)
{
    int one_sort[1] = { 1 };
    int expected[1] = { 1 };

    bubble_sort(one_sort, sizeof(one_sort) / sizeof(int));
    assert_sort_eq(one_sort, expected, 1);
}

Test(bubble_sort, two_sorted)
{
    int two_sort[2] = { 1, 2 };
    int expected[2] = { 1, 2 };

    bubble_sort(two_sort, sizeof(two_sort) / sizeof(int));
    assert_sort_eq(two_sort, expected, 2);
}

Test(bubble_sort, two)
{
    int two_sort[2] = { 2, 1 };
    int expected[2] = { 1, 2 };

    bubble_sort(two_sort, sizeof(two_sort) / sizeof(int));
    assert_sort_eq(two_sort, expected, 2);
}

Test(bubble_sort, first_unordered)
{
    int first_sort[5] = { 5, 1, 2, 3, 4 };
    int expected[5] = { 1, 2, 3, 4, 5 };

    bubble_sort(first_sort, sizeof(first_sort) / sizeof(int));
    assert_sort_eq(first_sort, expected, 5);
}

Test(bubble_sort, simple_unordered)
{
    int simple_sort[5] = { 5, 1, 4, 2, 8 };
    int expected[5] = { 1, 2, 4, 5, 8 };

    bubble_sort(simple_sort, sizeof(simple_sort) / sizeof(int));
    assert_sort_eq(simple_sort, expected, 5);
}

Test(bubble_sort, large)
{
    int large_sort[10] = { -3, -3, 8, -3, -3, 3, 3, -12, 12, 999999999 };
    int expected[10] = { -12, -3, -3, -3, -3, 3, 3, 8, 12, 999999999 };

    bubble_sort(large_sort, sizeof(large_sort) / sizeof(int));
    assert_sort_eq(large_sort, expected, 10);
}

Test(bubble_sort, multiple)
{
    int multiple_sort[6] = { 1, 3, 3, 3, 3, 3 };
    int expected[6] = { 1, 3, 3, 3, 3, 3 };

    bubble_sort(multiple_sort, sizeof(multiple_sort) / sizeof(int));
    assert_sort_eq(multiple_sort, expected, 6);
}

Test(bubble_sort, multiple_again)
{
    int multiple_sort[6] = { 3, 3, 3, 1, 3, 3 };
    int expected[6] = { 1, 3, 3, 3, 3, 3 };

    bubble_sort(multiple_sort, sizeof(multiple_sort) / sizeof(int));
    assert_sort_eq(multiple_sort, expected, 6);
}

Test(bubble_sort, negative)
{
    int negative_sort[6] = { -1, -6, 8, 12, -60, 5 };
    int expected[6] = { -60, -6, -1, 5, 8, 12 };

    bubble_sort(negative_sort, sizeof(negative_sort) / sizeof(int));
    assert_sort_eq(negative_sort, expected, 6);
}

Test(bubble_sort, some)
{
    int some_sort[10] = { 0, 7, 4, 8, 1, 5, 2, 3, 9, 6 };
    int expected[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    bubble_sort(some_sort, sizeof(some_sort) / sizeof(int));
    assert_sort_eq(some_sort, expected, 10);
}

Test(bubble_sort, some2)
{
    int some_sort[11] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int expected[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    bubble_sort(some_sort, sizeof(some_sort) / sizeof(int));
    assert_sort_eq(some_sort, expected, 11);
}

Test(bubble_sort, some3)
{
    int some_sort[11] = { 8, 5, 3, 1, 9, 5, 0, 5, 4, 2, 5 };
    int expected[11] = { 0, 1, 2, 3, 4, 5, 5, 5, 5, 8, 9 };

    bubble_sort(some_sort, sizeof(some_sort) / sizeof(int));
    assert_sort_eq(some_sort, expected, 11);
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
