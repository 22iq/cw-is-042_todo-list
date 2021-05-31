#include <ctest.h>
#include <libtodolist/task.h>
#include <string.h>
CTEST(check_characters_by_ASCII, chek_for_ascii)
{
    selected_list test;
    char test_name_task[153] = " love_trpo}\0";
    const int expect = 1;
    strcpy(test.name_task, test_name_task);

    const int result = check_characters_by_ASCII(&test);
    ASSERT_EQUAL(expect, result);

    char test_name_task1[153] = "~~~~~~~~\0";
    strcpy(test.name_task, test_name_task1);
    ASSERT_FALSE(check_characters_by_ASCII(&test));

    char test_name_task2[153] = "Мудрые люди говорят потому\0";
    strcpy(test.name_task, test_name_task2);
    ASSERT_FALSE(check_characters_by_ASCII(&test));
}
CTEST(search_last_task, test_last_task)
{
    selected_list sl;
    const int expect = 3;
    FILE* file = fopen("test.txt", "w");
    for (size_t i = 1; i <= 3; i++) {
        fwrite("Xtask", sizeof(char), 5, file);
        for (size_t j = 1; j <= (151 - 5); j++) {
            fputc('~', file);
        }
    }

    rewind(file);
    const int result = search_last_task(&sl, file);
    ASSERT_EQUAL(expect, result);
    fclose(file);
    remove("test.txt");
} 
CTEST(get_amount_task, test_amount_task)
{
    remove("test.txt");
    selected_list sl;
    const int expect = 5;
    FILE* file = fopen("test.txt", "w+");
    for (size_t i = 1; i <= 5; i++) {
        fwrite("Xtask", sizeof(char), 5, file);
        for (size_t j = 1; j <= (151 - 5); j++) {
            fputc('~', file);
        }
    }
    for (size_t i = 1; i <= 3; i++) {
        fwrite("\0", sizeof(char), 1, file);
        for (size_t j = 1; j <= (151 - 1); j++) {
            fputc('~', file);
        }
    }

    rewind(file);
    const int result = get_amount_task(&sl, file);
    ASSERT_EQUAL(expect, result);
    fclose(file);
    remove("test.txt");
}