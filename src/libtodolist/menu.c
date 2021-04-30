#include "menu.h"

#include <stdlib.h>

void list_menu()
{
    selected_list sl;
    unsigned int select;

    do {
        system("clear");

        // print_lists();
        printf("1. Create list\n");
        printf("2. Select list\n");
        printf("3. Exit the program\n\n");

        do {
            scanf("%d", &select);
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

    unsigned int select;

    // print_lists();
    // do {
    scanf("%d", &select);
    //} while (get_list(select, sl));
    choose_action_list(sl);
}

void choose_action_list(selected_list* sl)
{
    system("clear");

    unsigned int select;

    // printf selected list
    printf("1. Delete list\n");
    printf("2. Rename list\n");
    printf("3. Open list\n");
    printf("4. Back\n\n");

    do {
        scanf("%d", &select);
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
    unsigned int select;
    // fopen file .txt

    do {
        system("clear");

        // printf selected list
        // print_tasks(); or printf todolist is empty
        printf("1. Create task\n");

        // unused if todolist is empty
        printf("2. Select task\n");
        printf("3. Back\n\n");

        do {
            scanf("%d", &select);
        } while (select == 0 || select > 3);

        switch (select) {
        case 1:
            // create_task(sl, file);
            break;
        case 2:
            // select_task(sl, file);
            break;
        case 3:
            // fclose(file);
            return;
        }
    } while (1);
}

void select_task(selected_list* sl, FILE* file)
{
    system("clear");

    unsigned int select;

    // print_tasks();
    // do {
    scanf("%d", &select);
    //} while (get_task(select, sl));
    choose_action_task(sl, file);
}

void choose_action_task(selected_list* sl, FILE* file)
{
    system("clear");

    unsigned int select;

    // printf selected task
    printf("1. Delete task\n");

    // unused if task is completed
    printf("2. Edit task\n");
    printf("3. Mark task as completed\n");
    printf("4. Back\n\n");

    do {
        scanf("%d", &select);
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