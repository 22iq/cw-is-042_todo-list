#include "get_task.h"
#include "task.h"

size_t get_task(size_t select, selected_list* sl, FILE* list)
{
    fseek(list, 0, SEEK_END);
    size_t bytes = sizeof(sl->name_task) - 2 * sizeof(char);
    if (select > get_amount_task(sl, list) || select == 0) {
        return 1;
    }
    fseek(list,
          (get_number_task_in_file(sl, list, select) - 1) * bytes,
          SEEK_SET);
    fread(sl->name_task, sizeof(char), bytes, list);
    rewind(list);
    return 0;
}