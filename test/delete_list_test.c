#include <ctest.h>
#include <libtodolist/delete_list.h>
#include <libtodolist/selected_list_type.h>
#include <string.h>

CTEST(delete_list, correct_input_with_valid_characters)
{
    selected_list test;
    char test_name_file[36] = "Default.txt\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 2;

    const int result = delete_list(&test);
    ASSERT_EQUAL(expect, result);
}
CTEST(delete_list, correct_input_1)
{
    selected_list test;
    char test_name_file[36] = "FILE.txt\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = delete_list(&test);
    ASSERT_EQUAL(expect, result);
}
CTEST(delete_list, correct_input_2)
{
    selected_list test;
    char test_name_file[36] = "files.txt\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = delete_list(&test);
    ASSERT_EQUAL(expect, result);
}
