/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: safe way to scan
* Author: Paula Gelman
-------------------------------------------------------*/
/*
הקוד רץ  לפני כן לכן לא הבנתי את הredo
כי MAX_SIZE הוא גודל שמור -בשבילו הבאתי את ה
 #include <limits.h>
ברגע שאני מנסה ליצור לו דפיין אני דורסת את הגודל הקיים וזה עושה לי שגיאה:()

*/
#include <stdio.h>  
#include <stdlib.h>    
#include <limits.h>//I found on the internet a way to check what the  MAX SIZE
                  //  of size_t

#define INITIAL_SIZE 12 // initial buffer size (in case of int:10 digits,'-','\0')
char* dyn_scanf(void) {
    char *buffer = NULL; // dynamic string
    size_t size = 0;  // current  size of buffer
    size_t len = 0; // number of characters
    int ch; 

    // Read characters until newline or EOF
    while (1) {
        ch = getchar();
        if (ch=='\n' || ch==EOF) {
            break;
        }
        // We need space for new character and '\0'
        if (len+1 >= size) {
            size_t newSize;

            if (size == 0) {
                newSize = INITIAL_SIZE;
            } else {
                // size > SIZE_MAX/2 -> size * 2 would overflow size_t
                if (size > (SIZE_MAX / 2)) {
                    free(buffer);
                    return NULL;
                }

                newSize=size*2; //else :make the size bigger
            }

            //in case newSize smaller than len + 1(no enough space)
            if (newSize <= len+1) {
                free(buffer);
                return NULL;
            }

             //try to realloc the buffer with the new size
            char *tmp = (char*)realloc(buffer, newSize);
            if (tmp == NULL) {
                free(buffer);
                return NULL;
            }
            buffer=tmp;
            size=newSize;
        }
        //add new character to the buffer
        buffer[len++] = (char)ch;
    }

    //no characterswere read 
    if (len==0 && ch==EOF) {
        return NULL;
    }

    if (len == SIZE_MAX) {
        free(buffer);
        return NULL;
    }

    //new size the buffer to the : length + '\0'
    char *tmp = (char*)realloc(buffer, len + 1);
    if (tmp == NULL) {
        free(buffer);
        return NULL;
    }

    buffer = tmp;
    buffer[len] = '\0';
    return buffer; 
}

int main(void) {

    printf_s("Enter line: ");

    char *line = dyn_scanf();
    if (line == NULL) {
        printf_s("No input or memory allocation error.\n");
        return 1;
    }

    printf_s("You entered: %s\n", line);


    free(line);
    return 0;
}
