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
void create_task(selected_list* sl, FILE* file)
{
    sl->name_task[0] = 'X';
    fgets(&sl->name_task[1], 150, stdin);
    if (!check_characters_by_ASCII(sl, file)) {
        printf("You have entered a symbol that our program does not support, "
               "please try again");
    } else {
        fwrite(sl->name_task, sizeof(char), 151, file);
    }
}
int search_last_task(selected_list* sl, FILE* file)
{
    size_t number_last_task = 0;
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fgets(sl->name_task, 150, file);
        number_last_task++;
    }
    return number_last_task;
    rewind(file);
}
void delete_task(selected_list* sl, FILE* file, size_t number_task)
{
    size_t number_delete_task = number_task;
    size_t number_last_task = search_last_task(sl, file);
    size_t bytes_to_delit = (number_delete_task)*150;
    fseek(file, bytes_to_delit, SEEK_SET);
    if (number_delete_task <= number_last_task) {
        sl->name_task[0] = 0;
    } else {
        printf("The task you entered does not exist");
    }
    rewind(file);
}
void edit_task(selected_list* sl, FILE* file, size_t number_task)
{
    size_t number_edit_task = number_task;
    size_t number_last_task = search_last_task(sl, file);
    size_t bytes_to_delit = (number_edit_task)*150;
    fseek(file, bytes_to_delit, SEEK_SET);
    if (number_edit_task <= number_last_task) {
        for (int i = 0; i < 150; i++) {
            sl->name_task[i] = ' ';
        }
        fgets(sl->name_task, 150, stdin);
        if (!check_characters_by_ASCII(sl, file)) {
            printf("You have entered a symbol that our program does not "
                   "support, "
                   "please try again");
        } else {
            fwrite(sl->name_task, sizeof(char), 151, file);
        }
    } else {
        printf("The task you entered does not exist");
    }
    rewind(file);
}
