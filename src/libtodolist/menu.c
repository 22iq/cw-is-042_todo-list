#include "menu.h"

#include "completed_task.h"
#include "get_list.h"
#include "get_task.h"
#include "print_lists.h"
#include "print_tasks.h"

#include <stdlib.h>
#include <string.h>

void list_menu()
{
    selected_list sl;
    size_t select;

    do {
        system("clear");

        print_lists();
        printf("\n1. Create list\n");
        printf("2. Select list\n");
        printf("3. Exit the program\n\n");

        do {
            scanf("%lu", &select);
        } while (select == 0 || select > 3);

        switch (select) {
        case 1:
            // create_list(sl);
            break;
        case 2:
            select_list(&sl);
            break;
        case 3:
            return;
        }
    } while (1);
}

void select_list(selected_list* sl)
{
    system("clear");

    size_t select;

    print_lists();
    do {
        scanf("%lu", &select);
    } while (get_list(select, sl));
    choose_action_list(sl);
}

void choose_action_list(selected_list* sl)
{
    system("clear");

    size_t select;

    // printf selected list
    printf("1. Delete list\n");
    printf("2. Rename list\n");
    printf("3. Open list\n");
    printf("4. Back\n\n");

    do {
        scanf("%lu", &select);
    } while (select == 0 || select > 4);

    switch (select) {
    case 1:
        // delete_list(sl);
        break;
    case 2:
        // rename_list(sl);
        break;
    case 3:
        open_list(sl);
    case 4:
        return;
    }
}

void open_list(selected_list* sl)
{
    size_t select;

    // get full path
    char path[44] = "./lists/";
    strcat(path, sl->name_list);

    FILE* list = fopen(path, "r+");

    do {
        system("clear");

        size_t count = 1;
        size_t list_is_empty = 0;

        print_selected_list(sl);
        print_tasks(sl, list, &list_is_empty);
        printf("\n%lu. Create task\n", count++);

        // unused if todolist is empty
        if (!list_is_empty) {
            printf("%lu. Select task\n", count++);
        }
        printf("%lu. Back\n\n", count);

        do {
            scanf("%lu", &select);
        } while (select == 0 || select > count);

        switch (select) {
        case 1:
            // create_task(sl, list);
            break;
        case 2:
            if (list_is_empty) {
                fclose(list);
                return;
            }
            select_task(sl, list);
            break;
        case 3:
            fclose(list);
            return;
        }
    } while (1);
}

void select_task(selected_list* sl, FILE* list)
{
    system("clear");

    size_t select;

    print_tasks(sl, list, false);
    do {
        scanf("%lu", &select);
    } while (get_task(select, sl, list));
    choose_action_task(sl, list, select);
}

void choose_action_task(selected_list* sl, FILE* list, size_t number_task)
{
    system("clear");

    size_t select;

    print_selected_task(sl);
    printf("1. Delete task\n");

    // unused if task is completed
    printf("2. Edit task\n");
    printf("3. Mark task as completed\n");
    printf("4. Back\n\n");

    do {
        scanf("%lu", &select);
    } while (select == 0 || select > 4);

    switch (select) {
    case 1:
        // delete_task(sl, list);
        break;
    case 2:
        // edit_task(sl, list);
        break;
    case 3:
        completed_task(sl, list, number_task);
    case 4:
        return;
    }
}