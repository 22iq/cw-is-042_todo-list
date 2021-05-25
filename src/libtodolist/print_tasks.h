#pragma once

#include "selected_list_type.h"

#include <stdio.h>

#define true 1
#define false 0

void print_tasks(selected_list* sl, FILE* list, size_t* list_is_empty);
void print_selected_list(selected_list* sl);