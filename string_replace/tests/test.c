#include <criterion/criterion.h>
#include <string.h>

char *string_replace(char c, const char *str, const char *pattern);

static void check_res(char c, const char *str, const char *pattern,
                      const char *expected)
{
    char *student_res = string_replace(c, str, pattern);
    if (!student_res)
        cr_assert_null(str);
    else
    {
        // Avoid displaying non utf8 chars
        cr_assert_eq(strlen(student_res), strlen(expected));
        // Actually check the result
        cr_assert_str_eq(student_res, expected);
    }
    free(student_res);
}

TestSuite(string_replace, .timeout = 15);

Test(string_replace, null)
{
    check_res('o', NULL, "pattern", NULL);
}

Test(string_replace, twice_null)
{
    check_res('o', NULL, NULL, NULL);
}

Test(string_replace, acu)
{
    check_res('z', "zazczuz", NULL, "acu");
}

Test(string_replace, empty)
{
    check_res('i', "", "oo", "");
}

Test(string_replace, empty_pattern)
{
    check_res('i', "bibi", "", "bb");
}

Test(string_replace, both_empty)
{
    check_res('i', "", "", "");
}

Test(string_replace, numbers)
{
    check_res('0', "1010", "1", "1111");
}

Test(string_replace, booboo)
{
    check_res('i', "bibi", "oo", "booboo");
}

Test(string_replace, bibi)
{
    check_res('i', "biibii", "oo", "booooboooo");
}

Test(string_replace, noreplace)
{
    check_res('i', "bobo", "o", "bobo");
}

Test(string_replace, replaceall)
{
    check_res('i', "ii", "o", "oo");
}

Test(string_replace, bigby)
{
    check_res('I', "BigbI", "y", "Bigby");
}

Test(string_replace, bigbo)
{
    check_res('O', "BoBoo", "I", "BoBoo");
}

Test(string_replace, bouzigouloum)
{
    check_res('<', "b<uzig<ul<um", "o", "bouzigouloum");
}

Test(string_replace, a_song_of_ice_and_fire)
{
    check_res('"', "a\"song\"of\"ice\"and\"fire", " ",
              "a song of ice and fire");
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
