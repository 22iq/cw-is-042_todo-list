#include "rename_list.h"
#include <stdio.h>
#include <string.h>

int rename_list(selected_list* v, char* newnamefile)
{
    //Переменные

    char txt_file[] = ".txt";
    char oldnamefile[45] = "./lists/";
    char wayfile[45] = "./lists/";
    //Ввод названия файла
    if ((newnamefile[31] == '\0') && (newnamefile[30] != '\n')) {
        return 1;
    }
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
        return 3;
    }
    //Проверка
    for (size_t i = 0; i < 31; i++) {
        if (newnamefile[i] == '\n') {
            newnamefile[i] = '\0';
        }
        if ((newnamefile[i] >= 'A' && newnamefile[i] <= 'Z')
            || (newnamefile[i] >= 'a' && newnamefile[i] <= 'z')
            || (newnamefile[i] >= '0' && newnamefile[i] <= '9')
            || (newnamefile[i] >= '\0')) {
        } else {
            return 2;
        }
    }
    strcat(newnamefile, txt_file);
    strcat(wayfile, newnamefile);
    //Проверка ниличия файла
    FILE* filetest = fopen(wayfile, "r+");
    if (filetest != NULL) {
        fclose(filetest);
        return 4;
    }

    //Переименовать
    strcat(oldnamefile, v->name_list);
    rename(oldnamefile, wayfile);
    strcpy(v->name_list, newnamefile);
    return 0;
}
// return 0 - Всё отлично
// return 1 - Превышено допустимое кол-во символов
// return 2 - Недопустимое значение символов
// return 3 - Недопустимое название файла
// return 4 - Такой файл существует