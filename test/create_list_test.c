#include "src/libtodolist/selected_list_type.h"
#include <ctest.h>
#include <libtodolist/create_list.h>
#include <string.h>

CTEST(create_list, correct_input_with_valid_characters)
{
    selected_list test;
    char test_name_file[36] = "File 123\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, correct_input_in_capital_letters)
{
    selected_list test;
    char test_name_file[36] = "FILE\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, correct_input_in_small_letters)
{
    selected_list test;
    char test_name_file[36] = "file\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, incorrect_input_with_large_number_of_characters)
{
    selected_list test;
    char test_name_file[36] = "name with a large number of characters\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 1;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, incorrect_input_with_invalid_characters)
{
    selected_list test;
    char test_name_file[36] = "Кириллица\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 2;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, correct_input_of_an_invalid_name)
{
    selected_list test;
    char test_name_file[36] = "PRN\0";

    strcpy(test.name_list, test_name_file);
    const int expect = 3;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}