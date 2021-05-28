#pragma once
#include "selected_list_type.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_characters_by_ASCII(selected_list* sl, FILE* file);
void create_task(selected_list* sl, FILE* file);
int search_last_task(selected_list* sl, FILE* file);
void delete_task(selected_list* sl, FILE* file, size_t number_task);
void edit_task(selected_list* sl, FILE* file, size_t number_task);
