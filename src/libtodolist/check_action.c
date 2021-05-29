#include "check_action.h"

#include <stdlib.h>

size_t check_action(char* command)
{
    char c, next;
    system("clear");
    printf("Do you really want to %s?\nEnter Y/N: ", command);
    do {
        c = getchar();
        if ((next = getchar()) == '\n') {
            switch (c) {
            case 'Y':
                return 0;
            case 'N':
                return 1;
            }
        }
        while ((c = getchar()) != '\n')
            ;
    } while (1);
}