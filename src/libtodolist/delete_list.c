#include "delete_list.h"
#include <stdio.h>
#include <string.h>

int delete_list(selected_list* v)
{
    char txt_file[90] = ".txt";
    char wayfile[90] = "file/";

    strcat(wayfile, v->name_list);
    if (remove(wayfile) == NULL) {
        for (size_t i = 0; i < 30; i++) {
            v->name_list[i] = '\0';
        }
        return 1;
    } else {
        return 0;
    }
}