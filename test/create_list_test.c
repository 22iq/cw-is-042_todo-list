#include <ctest.h>
#include <libtodolist/create_list.h>
#include <libtodolist/selected_list_type.h>
#include <stdio.h>
#include <string.h>

CTEST(create_list, correct_input_with_valid_characters)
{
    selected_list test;
    char test_name_file[36] = "File 123\0";

    for (size_t i = 0; i < 35; i++) {
        test.name_list[i] = '1';
    }

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, correct_input_in_capital_letters)
{
    selected_list test;
    char test_name_file[36] = "FILE\0";

    for (size_t i = 0; i < 35; i++) {
        test.name_list[i] = '1';
    }

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);

    remove("./lists/FILE.txt");
}

CTEST(create_list, correct_input_in_small_letters)
{
    selected_list test;
    char test_name_file[36] = "files\0";

    for (size_t i = 0; i < 35; i++) {
        test.name_list[i] = '1';
    }

    strcpy(test.name_list, test_name_file);
    const int expect = 0;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);

    remove("./lists/files.txt");
}

CTEST(create_list, incorrect_input_with_large_number_of_characters)
{
    selected_list test;
    char test_name_file[] = "name with a large number of characters\0";

    for (size_t i = 0; i < 35; i++) {
        test.name_list[i] = '1';
    }

    strcpy(test.name_list, test_name_file);
    test.name_list[31] = '\0';
    const int expect = 1;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, incorrect_input_with_invalid_characters)
{
    selected_list test;
    char test_name_file[36] = "Кириллица\0";

    for (size_t i = 0; i < 35; i++) {
        test.name_list[i] = '1';
    }

    strcpy(test.name_list, test_name_file);
    const int expect = 2;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}

CTEST(create_list, correct_input_of_an_invalid_name)
{
    selected_list test;
    char test_name_file[36] = "PRN\0";

    for (size_t i = 0; i < 35; i++) {
        test.name_list[i] = '1';
    }

    strcpy(test.name_list, test_name_file);
    const int expect = 3;

    const int result = create_list(&test);
    ASSERT_EQUAL(expect, result);
}