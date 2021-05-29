#include "name_initialization.h"
#include <stdio.h>

void name_initialization(selected_list* v)
{
    for (size_t j = 0; j < 35; j++) {
        v->name_list[j] = '1';
    }
    fgets(v->name_list, 32, stdin);
}