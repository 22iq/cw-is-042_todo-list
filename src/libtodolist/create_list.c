#include "create_list.h"
#include <stdio.h>
#include <string.h>

int create_list(selected_list* v)
{
    //Переменные
    char namefile[36] = {1};
    char txt_file[] = ".txt";
    char wayfile[90] = "../lists/";

    //Ввод названия файла

    fgets(namefile, 32, stdin);

    if ((namefile[31] == '\0') && (namefile[30] != '\n')) {
        return 1;
    }

    //Проверка
    for (size_t i = 0; i < 31; i++) {
        if (namefile[i] == '\n') {
            namefile[i] = '\0';
        }
        if ((namefile[i] >= 'A' && namefile[i] <= 'Z')
            || (namefile[i] >= 'a' && namefile[i] <= 'z')
            || (namefile[i] >= '0' && namefile[i] <= '9')
            || (namefile[i] == '\0') || (namefile[i] == ' ')) {
        } else {
            return 2;
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
        return 3;
    }
    strcat(namefile, txt_file);
    strcat(wayfile, namefile);
    //Проверка ниличия файла
    FILE* filetest = fopen(wayfile, "r+");
    if (filetest != NULL) {
        return 4;
    }
    fclose(filetest);

    //Присоединение пути и расширения

    FILE* file = fopen(wayfile, "w");
    if (file != NULL) {
        strcpy(v->name_list, namefile);
    }
    fclose(file);

    return 0;
}
// return 0 - Всё отлично
// return 1 - Превышено допустимое кол-во символов
// return 2 - Недопустимое значение символов
// return 3 - Недопустимое название файла
// return 4 - Такой файл существует
