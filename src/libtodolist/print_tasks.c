#include "print_tasks.h"
#include "task.h"

void print_tasks(selected_list* sl, FILE* list, size_t* list_is_empty)
{
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    size_t count = 1, j;
    char is_del_task;

    // without del tasks
    size_t n = get_amount_task(sl, list);

    if (n == 0) {
        puts("This todolist is empty");
        *list_is_empty = true;
        return;
    }

    // with del tasks
    fseek(list, 0, SEEK_END);
    n = ftell(list) / bytes;
    rewind(list);

    for (; n > 0; n--) {
        fread(&is_del_task, sizeof(char), 1, list);
        fseek(list, -1, SEEK_CUR);
        if (is_del_task != '\0') {
            fread(sl->name_task, sizeof(char), bytes, list);
            for (j = 0; sl->name_task[j] != '~' && j < 151; j++)
                ;
            sl->name_task[j] = '\0';
            printf("%lu. %c|%s\n",
                   count++,
                   sl->name_task[0],
                   &sl->name_task[1]);
            sl->name_task[j] = '~';
        } else {
            fseek(list, bytes, SEEK_CUR);
        }
    }
    rewind(list);
}

void print_selected_task(selected_list* sl)
{
    size_t i;
    for (i = 0; sl->name_task[i] != '~' && i < 151; i++)
        ;
    sl->name_task[i] = '\0';
    printf("Selected task: %s\n\n", &sl->name_task[1]);
    sl->name_task[i] = '~';
}