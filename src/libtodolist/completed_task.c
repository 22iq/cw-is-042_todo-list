#include "completed_task.h"

void completed_task(selected_list* sl, FILE* list, size_t number_task)
{
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    fseek(list, (number_task - 1) * bytes, SEEK_SET);
    fwrite("O", sizeof(char), 1, list);
    rewind(list);
    sl->name_task[0] = 'O';
}