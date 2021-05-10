#pragma once
#include "selected_list_type.h"
#include <stdio.h>
#include <stdlib.h>

void create_task(selected_list* sl, FILE* file);
int search_last_task(selected_list* sl, FILE* file);
void delete_task(selected_list* sl, FILE* file);
void edit_task(selected_list* sl, FILE* file);
