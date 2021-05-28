#include "get_task.h"

size_t get_task(size_t select, selected_list* sl, FILE* list)
{
    fseek(list, 0, SEEK_END);
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    size_t amount_tasks = ftell(list) / bytes;
    if (select > amount_tasks) {
        return 1;
    }
    fseek(list, (select - 1) * bytes, SEEK_SET);
    fread(sl->name_task, sizeof(char), bytes, list);
    rewind(list);
    return 0;
}