#include <criterion/criterion.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init);

static int *test_calloc(size_t size, int init)
{
    int *my_ptr = my_calloc(size, init);
    cr_assert(my_ptr != NULL, "pointer should not be null");

    size_t realsize = malloc_usable_size(my_ptr);

    cr_assert(realsize >= (size * sizeof(int)),
              "Realsize size is too small: "
              "%lu instead of %lu",
              realsize, 2 * size * sizeof(int));
    cr_assert(realsize <= (2 * size * sizeof(int)),
              "Realsize size is too "
              "large: %lu instead of %lu",
              realsize, 2 * size * sizeof(int));

    return my_ptr;
}

static bool check_array(size_t size, int init, int *ptr)
{
    bool status = true;
    for (size_t i = 0; status && i < size; status &= ptr[i++] == init)
        ;
    return status;
}

TestSuite(my_calloc, .timeout = 15);

Test(my_calloc, simple)
{
    int *my_ptr = test_calloc(4, 1);
    cr_assert(my_ptr[0] == 1, "Array not initialized incorrectly");
    free(my_ptr);
}

Test(my_calloc, null)
{
    int *my_ptr = my_calloc(0, 1);
    cr_assert(my_ptr == NULL, "Array not null");
}

Test(my_calloc, zero)
{
    int *my_ptr = test_calloc(8, 0);
    cr_assert(check_array(8, 0, my_ptr), "Array not initialized correctly");
    free(my_ptr);
}

Test(my_calloc, overflow)
{
    int *my_ptr = my_calloc(-1, 0);
    cr_assert(my_ptr == NULL, "Array not null");
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
