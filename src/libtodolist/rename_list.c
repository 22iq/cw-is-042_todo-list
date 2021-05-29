#include "rename_list.h"
#include <stdio.h>
#include <string.h>

int rename_list(selected_list* v)
{
    //Переменные
    char newnamefile[30];
    char txt_file[90] = ".txt";
    char oldnamefile[90] = "file/";
    char wayfile[90] = "file/";

    //Ввод названия файла
    for (size_t i = 0; i < 30; i++) {
        newnamefile[i] = '\0';
    }
    fgets(newnamefile, 30, stdin);
    //
    if ((strcmp(newnamefile, "PRN") == 0) || (strcmp(newnamefile, "AUX") == 0)
        || (strcmp(newnamefile, "NUL") == 0)
        || (strcmp(newnamefile, "COM1") == 0)
        || (strcmp(newnamefile, "COM2") == 0)
        || (strcmp(newnamefile, "COM3") == 0)
        || (strcmp(newnamefile, "COM4") == 0)
        || (strcmp(newnamefile, "COM5") == 0)
        || (strcmp(newnamefile, "COM6") == 0)
        || (strcmp(newnamefile, "COM7") == 0)
        || (strcmp(newnamefile, "COM8") == 0)
        || (strcmp(newnamefile, "COM9") == 0)
        || (strcmp(newnamefile, "LPT1") == 0)
        || (strcmp(newnamefile, "LPT2") == 0)
        || (strcmp(newnamefile, "LPT3") == 0)
        || (strcmp(newnamefile, "LPT4") == 0)
        || (strcmp(newnamefile, "LPT5") == 0)
        || (strcmp(newnamefile, "LPT6") == 0)
        || (strcmp(newnamefile, "LPT7") == 0)
        || (strcmp(newnamefile, "LPT8") == 0)
        || (strcmp(newnamefile, "LPT9") == 0)) {
        return 0;
    }
    //Проверка
    for (size_t i = 0; i < 30; i++) {
        if (newnamefile[i] == '\n') {
            newnamefile[i] = '\0';
        }
        if ((newnamefile[i] >= 'A' && newnamefile[i] <= 'Z')
            || (newnamefile[i] >= 'a' && newnamefile[i] <= 'z')
            || (newnamefile[i] >= '0' && newnamefile[i] <= '9')
            || (newnamefile[i] >= '\0')) {
        } else {
            return 0;
        }
    }
    strcat(newnamefile, txt_file);
    strcat(wayfile, newnamefile);
    //Проверка ниличия файла
    FILE* filetest = fopen(wayfile, "r+");
    if (filetest != NULL) {
        return 2;
    }

    //Переименовать
    strcat(oldnamefile, v->name_list);
    rename(oldnamefile, wayfile);
    strcpy(v->name_list, newnamefile);
    return 1;
}