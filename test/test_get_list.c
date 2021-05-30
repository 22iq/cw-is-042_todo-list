#include <libtodolist/get_list.h>
#include <libtodolist/selected_list_type.h>

#include <ctest.h>
#include <stdio.h>

CTEST(get_list, invalid_values_select)
{
    selected_list sl;
    ASSERT_EQUAL(1, get_list(0, &sl));
    ASSERT_EQUAL(1, get_list(2, &sl));
}

CTEST(get_list, valid_values_select)
{
    selected_list sl;
    FILE* file = fopen("./lists/123.txt", "w");
    fclose(file);

    ASSERT_EQUAL(0, get_list(1, &sl));
    ASSERT_EQUAL(0, get_list(2, &sl));

    ASSERT_EQUAL(1, get_list(0, &sl));
    ASSERT_EQUAL(1, get_list(3, &sl));

    remove("./lists/123.txt");
}

CTEST(get_list, correct_input_to_namelist_default)
{
    selected_list sl;
    get_list(1, &sl);
    ASSERT_STR("Default.txt", sl.name_list);

    FILE* file = fopen("./lists/123.txt", "w");
    fclose(file);

    get_list(1, &sl);
    ASSERT_STR("Default.txt", sl.name_list);

    remove("./lists/123.txt");
}

CTEST(get_list, correct_input_to_namelist)
{
    selected_list sl;
    FILE* file = fopen("./lists/123.txt", "w");
    fclose(file);
    file = fopen("./lists/SSS.txt", "w");
    fclose(file);

    get_list(2, &sl);
    ASSERT_STR("123.txt", sl.name_list);

    get_list(3, &sl);
    ASSERT_STR("SSS.txt", sl.name_list);

    remove("./lists/123.txt");
    remove("./lists/SSS.txt");
}