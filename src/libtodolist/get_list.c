#include "get_list.h"

#include <dirent.h>
#include <stdio.h>
#include <string.h>

size_t get_list(size_t select, selected_list* sl)
{
    size_t pos_Def;
    struct dirent* dp;
    DIR* dir = opendir("./lists");
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, "Default.txt") == 0) {
            pos_Def = telldir(dir) - 1;
        }
    }
    if (select <= telldir(dir) - 2 && select > 0) {
        if (select == 1) {
            strcpy(sl->name_list, "Default.txt");
        } else {
            seekdir(dir, select);
            dp = readdir(dir);
            if (select >= pos_Def) {
                dp = readdir(dir);
            }
            char* dotp = strchr(dp->d_name, '.');
            strncpy(sl->name_list, dp->d_name, dotp - dp->d_name + 4);
            sl->name_list[dotp - dp->d_name + 4] = '\0';
        }
        closedir(dir);
        return 0;
    }
    closedir(dir);
    return 1;
}