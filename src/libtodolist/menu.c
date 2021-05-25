#include "menu.h"

#include "get_list.h"
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

    FILE* list = fopen(path, "r");

    do {
        system("clear");

        print_selected_list(sl);

        // print_tasks(); or printf todolist is empty
        print_tasks(sl, list);
        printf("\n1. Create task\n");

        // unused if todolist is empty
        printf("2. Select task\n");
        printf("3. Back\n\n");

        do {
            scanf("%lu", &select);
        } while (select == 0 || select > 3);

        switch (select) {
        case 1:
            // create_task(sl, list);
            break;
        case 2:
            // select_task(sl, list);
            break;
        case 3:
            fclose(list);
            return;
        }
    } while (1);
}

void select_task(selected_list* sl, FILE* file)
{
    system("clear");

    size_t select;

    // print_tasks();
    // do {
    scanf("%lu", &select);
    //} while (get_task(select, sl));
    choose_action_task(sl, file);
}

void choose_action_task(selected_list* sl, FILE* file)
{
    system("clear");

    size_t select;

    // printf selected task
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
        // delete_task(sl, file);
        break;
    case 2:
        // edit_task(sl, file);
        break;
    case 3:
        // completed_task(sl, file);
    case 4:
        return;
    }
}