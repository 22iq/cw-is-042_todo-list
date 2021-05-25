#include "print_tasks.h"

void print_tasks(selected_list* sl, FILE* list, size_t* list_is_empty)
{
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    size_t count = 1, j;

    // get amount of tasks
    fseek(list, 0, SEEK_END);
    size_t n = ftell(list) / bytes;
    rewind(list);

    if (n == 0) {
        puts("This todolist is empty");
        *list_is_empty = true;
        return;
    }

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

void print_selected_list(selected_list* sl)
{
    size_t i;
    for (i = 0; sl->name_list[i] != '.'; i++)
        ;
    sl->name_list[i] = '\0';
    printf("Selected list: %s\n\n", sl->name_list);
    sl->name_list[i] = '.';
}