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
    printf("Always enter X as the first character, f as the second task number "
           "and period");
    fgets(sl->name_task, 150, stdin);
    /*
    int number_task;
    printf("Enter the task number\n");
    scanf("%d", &number_task);
    printf("%d.", number_task);*/
    if (!check_characters_by_ASCII(sl, file)) {
        printf("You have entered a symbol that our program does not support, "
               "please try again");
    } else {
        fwrite(sl->name_task, sizeof(char), 151, file);
    }
}
int search_last_task(selected_list* sl, FILE* file)
{
    int number_last_task = 0;
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fgets(sl->name_task, 150, file);
        number_last_task++;
    }
    return number_last_task;
}
void delete_task(selected_list* sl, FILE* file)
{
    int number_delete_task;
    unsigned int select;
    int number_last_task = search_last_task(sl, file);
    printf("Select the task you want to delete:");
    scanf("%d\n\n", &number_delete_task);
    int bytes_to_delit = (number_delete_task)*150;
    fseek(file, bytes_to_delit, SEEK_SET);
    if (number_delete_task <= number_last_task) {
        printf("Are you sure you want to delete the task?\nIf you agree press "
               "Y, if not press N");
        scanf("%d", &select);
        switch (select) {
        case 'Y':
            sl->name_task[0] = 0;
            break;
        case 'N':
            break;
        }
    } else {
        printf("The task you entered does not exist");
    }
}
void edit_task(selected_list* sl, FILE* file)
{
    int number_edit_task;
    unsigned int select;
    int number_last_task = search_last_task(sl, file);
    printf("Select the task you want to edit:");
    scanf("%d\n\n", &number_edit_task);
    int bytes_to_delit = (number_edit_task)*150;
    fseek(file, bytes_to_delit, SEEK_SET);
    if (number_edit_task <= number_last_task) {
        printf("Are you sure you want to edit the task?\nIf you agree press Y, "
               "if not press N");
        scanf("%d", &select);
        switch (select) {
        case 'Y':
            for (int i = 0; i < 150; i++) {
                sl->name_task[i] = ' ';
            }
            fgets(sl->name_task, 150, stdin);
            int i = 0;
            while (sl->name_task[i] != '\0') {
                if (!((sl->name_task[i] >= ' ' && sl->name_task[i] <= '}'))) {
                    printf("Repeat again\n");
                    break;
                }
                ++i;
            }
            fwrite(sl->name_task, sizeof(char), 151, file);
            break;
        case 'N':
            break;
        }
    } else {
        printf("The task you entered does not exist");
    }
}
