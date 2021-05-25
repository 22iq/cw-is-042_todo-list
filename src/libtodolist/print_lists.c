#include "print_lists.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_lists()
{
    size_t i = 2;
    struct dirent* dp;
    DIR* dir = opendir("./lists");
    if (dir == NULL) {
        printf("Can not open dir\n");
        exit(EXIT_FAILURE);
    }

    seekdir(dir, 2);
    puts("1. Default");
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp("Default.txt", dp->d_name) != 0) {
            char* dot = strchr(dp->d_name, '.');
            *dot = '\0';
            printf("%lu. %s\n", i++, dp->d_name);
        }
    }

    closedir(dir);
}

void print_selected_list(selected_list* sl)
{
    size_t i;
    for (i = 0; sl->name_list[i] != '.'; i++)
        ;
    sl->name_list[i] = '\0';
    printf("Selected list: %s\n\n", sl->name_list);
    sl->name_list[i] = '.';
}