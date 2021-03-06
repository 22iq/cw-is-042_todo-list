#include "delete_list.h"
#include <stdio.h>
#include <string.h>

int delete_list(selected_list* v)
{
    char wayfile[45] = "./lists/";

    if (strcmp(v->name_list, "Default.txt") == 0)
        return 2;

    strcat(wayfile, v->name_list);
    if (remove(wayfile) == 0) {
        for (size_t i = 0; i < 35; i++) {
            v->name_list[i] = '\0';
        }
        return 0;
    } else {
        return 1;
    }
}
// return 0 - Всё отлично
// return 1 - Такого файла не существует
// return 2 - Default.txt