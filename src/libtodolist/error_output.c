#include "error_output.h"

void error_output(size_t func, size_t error_code)
{
    switch (func) {
    // func create_list or func rename_list
    case 1:
        switch (error_code) {
        case 1:
            printf("\nError: Number of characters exceeded");
            clear_buf();
            break;
        case 2:
            printf("\nError: Invalid character present");
            break;
        case 3:
            printf("\nError: Invalid file name");
            break;
        case 4:
            printf("\nError: The list already exists");
            break;
        case 5:
            printf("\nError: The main list cannot be renamed");
            break;
        case 6:
            printf("\nError: Empty list name");
        }
        break;

    // func get_list
    case 2:
        printf("\nError: The selected list does not exist\nSelect list: ");
        break;

    // func delete_list
    case 3:
        switch (error_code) {
        case 1:
            printf("\nError: List deletion error");
            break;
        case 2:
            printf("\nError: The main list cannot be deleted");
        }
        break;

    // func create_task of func edit_task
    case 4:
        switch (error_code) {
        case 1:
            printf("\nError: Number of characters exceeded");
            break;
        case 2:
            printf("\nError: Invalid character present");
            break;
        case 3:
            printf("\nError: Empty task introduced");
        }
        break;

    // func get_task
    case 5:
        printf("\nError: The selected task does not exist\nSelect task: ");
    }
}

void clear_buf()
{
    char c = ' ';
    do {
        c = getchar();
    } while (c != '\n');
}