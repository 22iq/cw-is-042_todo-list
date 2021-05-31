#include "get_number_selected_action.h"

void get_number_selected_action(size_t* select, size_t right)
{
    printf("Select cmd: ");
    do {
        scanf("%lu", select);
    } while (*select == 0 || *select > right);
    getchar();
}