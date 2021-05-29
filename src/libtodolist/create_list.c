#include "create_list.h"
#include <stdio.h>
#include <string.h>

int create_list(selected_list* v)
{
    //Переменные
    char namefile[30] = {0};
    char txt_file[90] = ".txt";
    char wayfile[90] = "file/";

    //Ввод названия файла

    fgets(namefile, 30, stdin);

    //Проверка
    for (size_t i = 0; i < 30; i++) {
        if (namefile[i] == '\n') {
            namefile[i] = '\0';
        }
        if ((namefile[i] >= 'A' && namefile[i] <= 'Z')
            || (namefile[i] >= 'a' && namefile[i] <= 'z')
            || (namefile[i] >= '0' && namefile[i] <= '9')
            || (namefile[i] == '\0') || (namefile[i] == ' ')) {
        } else {
            return 0;
        }
    }
    if ((strcmp(namefile, "PRN") == 0) || (strcmp(namefile, "AUX") == 0)
        || (strcmp(namefile, "NUL") == 0) || (strcmp(namefile, "COM1") == 0)
        || (strcmp(namefile, "COM2") == 0) || (strcmp(namefile, "COM3") == 0)
        || (strcmp(namefile, "COM4") == 0) || (strcmp(namefile, "COM5") == 0)
        || (strcmp(namefile, "COM6") == 0) || (strcmp(namefile, "COM7") == 0)
        || (strcmp(namefile, "COM8") == 0) || (strcmp(namefile, "COM9") == 0)
        || (strcmp(namefile, "LPT1") == 0) || (strcmp(namefile, "LPT2") == 0)
        || (strcmp(namefile, "LPT3") == 0) || (strcmp(namefile, "LPT4") == 0)
        || (strcmp(namefile, "LPT5") == 0) || (strcmp(namefile, "LPT6") == 0)
        || (strcmp(namefile, "LPT7") == 0) || (strcmp(namefile, "LPT8") == 0)
        || (strcmp(namefile, "LPT9") == 0)) {
        return 0;
    }
    strcat(namefile, txt_file);
    strcat(wayfile, namefile);
    //Проверка ниличия файла
    FILE* filetest = fopen(wayfile, "r+");
    if (filetest != NULL) {
        return 0;
    }

    //Присоединение пути и расширения

    FILE* file = fopen(wayfile, "w");
    if (file != NULL) {
        strcpy(v->name_list, namefile);
    }

    return 1;
}