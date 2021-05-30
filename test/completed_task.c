#include <libtodolist/completed_task.h>
#include <libtodolist/selected_list_type.h>

#include <ctest.h>
#include <stdio.h>

CTEST(completed_task, test)
{
    selected_list sl;
    char c = ' ';
    FILE* file = fopen("test.txt", "w+");
    for (size_t i = 1; i <= 3; i++) {
        fwrite("Xtask", sizeof(char), 5, file);
        for (size_t j = 1; j <= (151 - 5); j++) {
            fputc('~', file);
        }
    }

    rewind(file);
    completed_task(&sl, file, 1);
    c = fgetc(file);
    ASSERT_EQUAL('O', c);

    fseek(file, 151, SEEK_SET);
    completed_task(&sl, file, 2);
    c = fgetc(file);
    ASSERT_EQUAL('O', c);

    fseek(file, 302, SEEK_SET);
    completed_task(&sl, file, 3);
    c = fgetc(file);
    ASSERT_EQUAL('O', c);

    fclose(file);
    remove("test.txt");
}