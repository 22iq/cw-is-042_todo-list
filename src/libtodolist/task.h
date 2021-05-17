#pragma once
#include "selected_list_type.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool check_characters_by_ASCII(selected_list* sl, FILE* file);
void create_task(selected_list* sl, FILE* file);
int search_last_task(selected_list* sl, FILE* file);
void delete_task(selected_list* sl, FILE* file);
void edit_task(selected_list* sl, FILE* file);
