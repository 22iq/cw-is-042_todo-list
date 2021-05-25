#include "print_tasks.h"

#include <stdio.h>

void print_tasks(selected_list* sl, FILE* list)
{
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    size_t count = 1, j;

    // get n tasks
    fseek(list, 0, SEEK_END);
    size_t n = ftell(list) / bytes;
    rewind(list);

    for (; n > 0; n--) {
        fread(sl->name_task, sizeof(char), bytes, list);
        for (j = 0; sl->name_task[j] != '~'; j++)
            ;
        sl->name_task[j] = '\0';
        printf("%lu. %c|%s\n", count++, sl->name_task[0], &sl->name_task[1]);
        sl->name_task[j] = '~';
    }
    rewind(list);
}