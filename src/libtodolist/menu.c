#include "menu.h"

#include "check_action.h"
#include "completed_task.h"
#include "create_list.h"
#include "delete_list.h"
#include "error_output.h"
#include "get_list.h"
#include "get_number_selected_action.h"
#include "get_task.h"
#include "name_initialization.h"
#include "press_any_key.h"
#include "print_lists.h"
#include "print_tasks.h"
#include "rename_list.h"

#include <stdlib.h>
#include <string.h>

void list_menu()
{
    selected_list sl;
    size_t select;

    do {
        system("clear");

        size_t error_code = 0;

        print_lists();
        printf("---------------");
        printf("\n1. Create list\n");
        printf("2. Select list\n");
        printf("3. Exit the program\n\n");

        get_number_selected_action(&select, 3);

        switch (select) {
        case 1:
            if (!check_action("create list")) {
                printf("\nInput name list:\n");
                name_initialization(&sl);
                if ((error_code = create_list(&sl)) != 0) {
                    error_output(1, error_code);
                }
            }
            break;
        case 2:
            select_list(&sl);
            break;
        case 3:
            return;
        }
        press_any_key_to_continue(error_code);
    } while (1);
}

void select_list(selected_list* sl)
{
    system("clear");

    size_t select;
    size_t error_code = 0;

    print_lists();
    printf("\nSelect list: ");
    do {
        scanf("%lu", &select);
        if ((error_code = get_list(select, sl)) != 0) {
            error_output(2, error_code);
        }
    } while (error_code);
    choose_action_list(sl);
}

void choose_action_list(selected_list* sl)
{
    system("clear");

    size_t select;
    size_t error_code = 0;
    char new_name_file[36];

    print_selected_list(sl);
    printf("1. Delete list\n");
    printf("2. Rename list\n");
    printf("3. Open list\n");
    printf("4. Back\n\n");

    get_number_selected_action(&select, 4);

    switch (select) {
    case 1:
        if (!check_action("delete list")) {
            if ((error_code = delete_list(sl)) != 0) {
                error_output(3, error_code);
            }
        }
        break;
    case 2:
        if (!check_action("rename list")) {
            printf("\nInput new name list:\n");
            if ((error_code
                 = rename_list(sl, new_name_initialization(new_name_file)))
                != 0) {
                error_output(1, error_code);
            }
        }
        break;
    case 3:
        open_list(sl);
    case 4:
        return;
    }
    press_any_key_to_continue(error_code);
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
        size_t error_code = 0;

        print_selected_list(sl);
        print_tasks(sl, list, &list_is_empty);
        printf("---------------");
        printf("\n%lu. Create task\n", count++);

        // unused if todolist is empty
        if (!list_is_empty) {
            printf("%lu. Select task\n", count++);
        }
        printf("%lu. Back\n\n", count);

        get_number_selected_action(&select, count);

        switch (select) {
        case 1:
            if (!check_action("create_task")) {
                printf("\nInput task:\n");
                sl->name_task[152] = '~';
                fgets(&sl->name_task[1], 152, stdin);
                if ((error_code = create_task(sl, list)) != 0) {
                    error_output(4, error_code);
                }
            }
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
        press_any_key_to_continue(error_code);
    } while (1);
}

void select_task(selected_list* sl, FILE* list)
{
    system("clear");

    size_t select;
    size_t error_code = 0;

    print_tasks(sl, list, false);
    printf("\nSelect task: ");
    do {
        scanf("%lu", &select);
        if ((error_code = get_task(select, sl, list)) != 0) {
            error_output(5, error_code);
        }
    } while (error_code);
    select = get_number_task_in_file(sl, list, select);
    choose_action_task(sl, list, select);
}

void choose_action_task(selected_list* sl, FILE* list, size_t number_task)
{
    system("clear");

    size_t select, count = 1;
    size_t error_code = 0;

    print_selected_task(sl);
    printf("%lu. Delete task\n", count++);

    // unused if task is completed
    if (sl->name_task[0] == 'X') {
        printf("%lu. Edit task\n", count++);
        printf("%lu. Mark task as completed\n", count++);
    }
    printf("%lu. Back\n\n", count);

    get_number_selected_action(&select, count);

    switch (select) {
    case 1:
        if (!check_action("delete task")) {
            delete_task(sl, list, number_task);
        }
        break;
    case 2:
        if (sl->name_task[0] == 'O') {
            return;
        }
        if (!check_action("edit task")) {
            printf("\nInput new task:\n");
            sl->name_task[152] = '~';
            fgets(&sl->name_task[1], 152, stdin);
            if ((error_code = edit_task(sl, list, number_task)) != 0) {
                error_output(4, error_code);
            }
        }
        break;
    case 3:
        if (!check_action("mark task as completed")) {
            completed_task(sl, list, number_task);
        }
    case 4:
        return;
    }
    press_any_key_to_continue(error_code);
}