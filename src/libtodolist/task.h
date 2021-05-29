#pragma once
#include "selected_list_type.h"
#include <stdbool.h>
#include <stdio.h>

bool check_characters_by_ASCII(selected_list* sl);
size_t create_task(selected_list* sl, FILE* file);
size_t search_last_task(selected_list* sl, FILE* file);
size_t delete_task(selected_list* sl, FILE* file, size_t number_task);
size_t edit_task(selected_list* sl, FILE* file, size_t number_task);
