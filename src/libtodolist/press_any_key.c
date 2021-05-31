#include "press_any_key.h"

void press_any_key_to_continue(size_t error_code)
{
    char c = ' ';
    if (error_code) {
        puts("\n\nPress any key to continue");
        do {
            c = getchar();
        } while (c != '\n');
    }
}