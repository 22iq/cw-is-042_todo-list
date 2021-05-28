#include "check_action.h"

#include <stdlib.h>

size_t check_action(char* command)
{
    char c = '1';
    size_t is_first_try = 1;
    system("clear");
    printf("Do you really want to %s?\nEnter Y/N: ", command);
    do {
        c = getchar();
        if (is_first_try) {
            switch (c) {
            case 'Y':
                return 0;
            case 'N':
                return 1;
            default:
                is_first_try = 0;
            }
        }
        if (c == '\n') {
            is_first_try = 1;
        }
    } while (1);
}