#include "task.h"
#include <stdio.h>
void create_task(selected_list* sl, FILE* file)
{
    printf("Always enter X as the first character, f as the second task number "
           "and period");
    fgets(sl->name_task, 150, stdin);
    int i = 0;
    while (sl->name_task[i] != '\0') {
        if (!((sl->name_task[i] >= ' ' && sl->name_task[i] <= '}'))) {
            printf("Repeat again\n");
            break;
        }
        ++i;
    }
    /*
    int number_task;
    printf("Enter the task number\n");
    scanf("%d", &number_task);
    printf("%d.", number_task);*/
    fwrite(sl->name_task, sizeof(char), 151, file);
}
