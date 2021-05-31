#include "create_list.h"
#include <stdio.h>
#include <string.h>

int create_list(selected_list* v)
{
    //Переменные
    char txt_file[] = ".txt";
    char wayfile[45] = "./lists/";

    //Ввод названия файла

    // if ((v->name_list[31] == '\0') && (v->name_list[30] != '\n')) {
    if ((v->name_list[31] == '\0') && (v->name_list[30] != '\n')) {
        return 1;
    }
    if (v->name_list[0] == '\n') {
        return 6;
    }

    //Проверка
    for (int i = 0; v->name_list[i] != '\0'; i++) {
        if (v->name_list[i] == '\n') {
            v->name_list[i] = '\0';
        }
        if ((v->name_list[i] >= 'A' && v->name_list[i] <= 'Z')
            || (v->name_list[i] >= 'a' && v->name_list[i] <= 'z')
            || (v->name_list[i] >= '0' && v->name_list[i] <= '9')
            || (v->name_list[i] == '\0') || (v->name_list[i] == ' ')) {
        } else {
            return 2;
        }
    }
    if ((strcmp(v->name_list, "PRN") == 0) || (strcmp(v->name_list, "AUX") == 0)
        || (strcmp(v->name_list, "NUL") == 0)
        || (strcmp(v->name_list, "COM1") == 0)
        || (strcmp(v->name_list, "COM2") == 0)
        || (strcmp(v->name_list, "COM3") == 0)
        || (strcmp(v->name_list, "COM4") == 0)
        || (strcmp(v->name_list, "COM5") == 0)
        || (strcmp(v->name_list, "COM6") == 0)
        || (strcmp(v->name_list, "COM7") == 0)
        || (strcmp(v->name_list, "COM8") == 0)
        || (strcmp(v->name_list, "COM9") == 0)
        || (strcmp(v->name_list, "LPT1") == 0)
        || (strcmp(v->name_list, "LPT2") == 0)
        || (strcmp(v->name_list, "LPT3") == 0)
        || (strcmp(v->name_list, "LPT4") == 0)
        || (strcmp(v->name_list, "LPT5") == 0)
        || (strcmp(v->name_list, "LPT6") == 0)
        || (strcmp(v->name_list, "LPT7") == 0)
        || (strcmp(v->name_list, "LPT8") == 0)
        || (strcmp(v->name_list, "LPT9") == 0)) {
        return 3;
    }
    strcat(v->name_list, txt_file);
    strcat(wayfile, v->name_list);
    //Проверка ниличия файла
    FILE* filetest = fopen(wayfile, "r+");
    if (filetest != NULL) {
        fclose(filetest);
        return 4;
    }

    //Присоединение пути и расширения

    FILE* file = fopen(wayfile, "w");
    if (file != NULL) {
        fclose(file);
    }

    return 0;
}
// return 0 - Всё отлично
// return 1 - Превышено допустимое кол-во символов
// return 2 - Недопустимое значение символов
// return 3 - Недопустимое название файла
// return 4 - Такой файл существует
// return 6 - Название пустое
