#include <libtodolist/get_list.h>
#include <libtodolist/selected_list_type.h>

#include <ctest.h>
#include <stdio.h>

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