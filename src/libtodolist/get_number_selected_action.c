#include "get_number_selected_action.h"

void get_number_selected_action(size_t* select, size_t right)
{
    do {
        scanf("%lu", select);
    } while (*select == 0 || *select > right);
}