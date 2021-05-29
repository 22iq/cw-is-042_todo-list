#include "task.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
bool check_characters_by_ASCII(selected_list* sl)
{
    int i = 0;
    while (sl->name_task[i] != '\0' && sl->name_task[i] != '\n') {
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
    size_t i, n;
    char c = ' ';
    sl->name_task[0] = 'X';
    if (sl->name_task[152] == '\0' && sl->name_task[151] != '\n') {
        do {
            c = getchar();
        } while (c != '\n');
        return 1;
    }
    if (!check_characters_by_ASCII(sl)) {
        return 2;
    }
    if (sl->name_task[1] == '\n') {
        return 3;
    }
    for (i = 0; sl->name_task[i] != '\0' && sl->name_task[i] != '\n'; i++)
        ;
    for (; i <= 152; i++) {
        sl->name_task[i] = '~';
    }
    rewind(file);
    n = search_last_task(sl, file);
    for (i = 0; i < n; i++) {
        fread(&c, sizeof(char), 1, file);
        fseek(file, -1, SEEK_CUR);
        if (c == '\0') {
            fwrite(sl->name_task, sizeof(char), 151, file);
            break;
        }
        fseek(file, 151, SEEK_CUR);
    }
    if (i == n) {
        fwrite(sl->name_task, sizeof(char), 151, file);
    }
    rewind(file);
    return 0;
}
size_t search_last_task(selected_list* sl, FILE* file)
{
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    fseek(file, 0, SEEK_END);
    size_t n = ftell(file) / bytes;
    rewind(file);
    return n;
}
size_t delete_task(selected_list* sl, FILE* file, size_t number_task)
{
    size_t number_delete_task = number_task;
    size_t number_last_task = search_last_task(sl, file);
    size_t bytes_to_delit = (number_delete_task - 1) * 151;
    fseek(file, bytes_to_delit, SEEK_SET);
    if (number_delete_task <= number_last_task) {
        fwrite("\0", sizeof(char), 1, file);
    } else {
        return 3;
    }
    rewind(file);
    return 0;
}
size_t edit_task(selected_list* sl, FILE* file, size_t number_task)
{
    char c = ' ';
    size_t i;
    size_t number_edit_task = number_task;
    size_t bytes_to_delit = (number_edit_task - 1) * 151;
    fseek(file, bytes_to_delit, SEEK_SET);
    sl->name_task[0] = 'X';
    if (sl->name_task[152] == '\0' && sl->name_task[151] != '\n') {
        do {
            c = getchar();
        } while (c != '\n');
        return 1;
    }
    if (!check_characters_by_ASCII(sl)) {
        return 2;
    }
    if (sl->name_task[1] == '\n') {
        return 3;
    }
    for (i = 0; sl->name_task[i] != '\0' && sl->name_task[i] != '\n'; i++)
        ;
    for (; i <= 152; i++) {
        sl->name_task[i] = '~';
    }
    fwrite(sl->name_task, sizeof(char), 151, file);
    rewind(file);
    return 0;
}
size_t get_amount_task(selected_list* sl, FILE* file)
{
    char c = ' ';
    size_t special_tasks = 0;
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    fseek(file, 0, SEEK_END);
    size_t n = ftell(file) / bytes;
    rewind(file);
    for (size_t i = 1; i <= n; i++) {
        fread(&c, sizeof(char), 1, file);
        if (c != '\0') {
            special_tasks++;
        }
        fseek(file, bytes - 1, SEEK_CUR);
    }
    rewind(file);
    return special_tasks;
}
size_t get_number_task_in_file(selected_list* sl, FILE* file, size_t select)
{
    char c = ' ';
    size_t number_in_file = 0, del_tasks = 0;
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    fseek(file, 0, SEEK_END);
    size_t n = ftell(file) / bytes;
    rewind(file);
    for (size_t i = 1; i <= n; i++) {
        fread(&c, sizeof(char), 1, file);
        number_in_file++;
        if (c == '\0') {
            del_tasks++;
        }
        if (number_in_file == select + del_tasks) {
            break;
        }
        fseek(file, bytes - 1, SEEK_CUR);
    }
    rewind(file);
    return number_in_file;
}