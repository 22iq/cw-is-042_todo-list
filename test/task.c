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
CTEST(delete_task, test_delete_task)
{
    selected_list sl;
    FILE* file = fopen("test.txt", "w+");
    for (size_t i = 1; i <= 3; i++) {
        fwrite("Xtask", sizeof(char), 5, file);
        for (size_t j = 1; j <= (151 - 5); j++) {
            fputc('~', file);
        }
    }

    rewind(file);
    delete_task(&sl, file, 2);
    fseek(file, 151, SEEK_SET);
    const char result = fgetc(file);
    ASSERT_EQUAL('\0', result);
    fclose(file);
    remove("test.txt");
}
CTEST(get_number_task_in_file, test_get_number_task_in_file)
{
    selected_list sl;
    const int expect = 9;
    FILE* file = fopen("test.txt", "w+");
    for (size_t i = 1; i <= 3; i++) {
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

    for (size_t i = 1; i <= 3; i++) {
        fwrite("Xtask", sizeof(char), 5, file);
        for (size_t j = 1; j <= (151 - 5); j++) {
            fputc('~', file);
        }
    }

    rewind(file);
    const int result = get_number_task_in_file(&sl, file, 6);
    ASSERT_EQUAL(expect, result);
    fclose(file);
    remove("test.txt");
}
CTEST(create_task, number_of_symbols_is_not_correct)
{
    //я знаю, что тестирование ситуации с переполнением бесмысленно, так как
    //из-за гетчар, оно устраняет проблему, но всё же, пусть будет
    selected_list test;
    FILE* file = fopen("test.txt", "w+");
    char test_name_task[190]
            = "Pour up (Drank), head shot (Drank)Sit down(Drank),stand "
              "up(Drank) Pass out(Drank), wake up(Drank) "
              "Faded(Drank),faded(Drank) Now I done grew up round some people "
              "livin their life in\0 ";
    test_name_task[0] = 'X';
    for (size_t i = 1; i < 153; i++) {
        test.name_task[i] = '1';
    }

    strcpy(test.name_task, test_name_task);
    const int expect = 0;

    const int result = create_task(&test, file);
    ASSERT_EQUAL(expect, result);
    fclose(file);
    remove("test.txt");
}
CTEST(create_task, empty_create_task_situation)
{
    selected_list test;
    FILE* file = fopen("test.txt", "w+");
    char test_name_task[2] = "X\n";
    for (size_t i = 0; i < 153; i++) {
        test.name_task[i] = '1';
    }

    strcpy(test.name_task, test_name_task);
    const int expect = 3;

    const int result = create_task(&test, file);
    ASSERT_EQUAL(expect, result);
    fclose(file);
    remove("test.txt");
}
CTEST(create_task, ascii_going_out)
{
    selected_list test;
    FILE* file = fopen("test.txt", "w+");
    char test_name_task[190]
            = "Wise men spea~~~~~~~~~k because they have something to say; "
              "fools because~~~~ they have to say something.\0 ";
    test_name_task[0] = 'X';
    for (size_t i = 1; i < 153; i++) {
        test.name_task[i] = '1';
    }

    strcpy(test.name_task, test_name_task);
    const int expect = 2;

    const int result = create_task(&test, file);
    ASSERT_EQUAL(expect, result);
    fclose(file);
    remove("test.txt");
}