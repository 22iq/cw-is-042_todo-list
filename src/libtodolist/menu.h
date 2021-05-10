#pragma once

#include "selected_list_type.h"
#include "task.h"
#include <stdio.h>

void list_menu();
void select_list(selected_list* sl);
void choose_action_list(selected_list* sl);
void open_list(selected_list* sl);
void select_task(selected_list* sl, FILE* file);
void choose_action_task(selected_list* sl, FILE* file);