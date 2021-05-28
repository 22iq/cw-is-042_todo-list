#include "task.h"
#include <stdio.h>
bool check_characters_by_ASCII(selected_list* sl, FILE* file)
{
    int i = 0;
    while (sl->name_task[i] != '\0') {
        if (!((sl->name_task[i] >= ' ' && sl->name_task[i] <= '}'))) {
            return false;
            break;
        }
        ++i;
    }
    return true;
}
size_t create_task(selected_list* sl, FILE* file)
{
    size_t i;
    sl->name_task[0] = 'X';
    fgets(&sl->name_task[1], 152, stdin);
    if (sl->name_task[152] == '\0' && sl->name_task[151] == '\n') {
        return 1;
    }
    if (!check_characters_by_ASCII(sl, file)) {
        return 2;
    }
    for (i = 0; sl->name_task[i] != '\0'; i++)
        ;
    for (; i <= 152; i++) {
        sl->name_task[i] = '~';
    }
    fwrite(sl->name_task, sizeof(char), 151, file);
    return 0;
}
size_t search_last_task(selected_list* sl, FILE* file)
{
    size_t number_last_task = 0;
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fgets(sl->name_task, 151, file);
        number_last_task++;
    }
    return number_last_task;
    rewind(file);
}
size_t delete_task(selected_list* sl, FILE* file, size_t number_task)
{
    size_t number_delete_task = number_task;
    size_t number_last_task = search_last_task(sl, file);
    size_t bytes_to_delit = (number_delete_task - 1) * 151;
    fseek(file, bytes_to_delit, SEEK_SET);
    if (number_delete_task <= number_last_task) {
        sl->name_task[0] = 0;
        fwrite("\0", sizeof(char), 1, file);
    } else {
        return 3;
    }
    rewind(file);
    return 0;
}
size_t edit_task(selected_list* sl, FILE* file, size_t number_task)
{
    size_t number_edit_task = number_task;
    size_t number_last_task = search_last_task(sl, file);
    size_t bytes_to_delit = (number_edit_task - 1) * 151;
    fseek(file, bytes_to_delit, SEEK_SET);
    if (number_edit_task <= number_last_task) {
        for (int i = 0; i < 150; i++) {
            sl->name_task[i] = ' ';
        }
        fgets(sl->name_task, 152, stdin);
        if (sl->name_task[152] == '\0' && sl->name_task[151] == '\n') {
            return 5;
        }
        if (!check_characters_by_ASCII(sl, file)) {
            return 4;
        } else {
            fwrite(sl->name_task, sizeof(char), 151, file);
        }
    } else {
        return 5;
    }
    rewind(file);
    return 0;
}
