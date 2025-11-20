/*------------------------------------------------------
* Filename: sort.c
* Description: sort strings by lenght and 
* Author: Paula Gelman
-------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define ERROR -1

#define INITIAL_SIZE 12 // initial buffer size (in case of int:10 digits,'-','\0')
#define SIZE_OF_INPUT 5

/*using the function from the privious exercise*/
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

/*I returned the same values as strcmp */
int cmp_by_length(const char *first_string, const char *second_string) {
    
    size_t length_first = strlen(first_string );
    size_t length_second = strlen(second_string);

    if (length_first < length_second) return -1;
    if (length_first> length_second) return 1;

    return 0; //same length
}


int bubble_sort_letters(void* strings,unsigned int size,int(*pointer_cmp)(const char*, const char*)){

      if (strings==NULL || pointer_cmp==NULL) {
        return ERROR;
    }
    //to scan the values
    void **string_tmp = (void**)strings;

    for (unsigned i=0 ; i<(size-1); ++i){
        for (unsigned j=0 ; j<size-1-i ; ++j){
            if (pointer_cmp(string_tmp[j],string_tmp[j+1]) == 1){
                //string_tmp[j] > string_tmp[j+1]
                void *tmp= string_tmp[j+1];
                string_tmp[j+1] = string_tmp[j];
                string_tmp[j] = tmp;
            }
            

        }
    }
     return 0;

}

int main(){

    int(*pointer_cmp)(const char*, const char*);
    pointer_cmp=&strcmp;
    void* strings[SIZE_OF_INPUT]={0};

    for(unsigned int i=0 ; i<SIZE_OF_INPUT ; i++){

        printf("Enter %d string",i+1);
        strings[i]=dyn_scanf();
    }
    
    //sort by ALPHABETI
    if(ERROR==bubble_sort_letters(strings,SIZE_OF_INPUT , cmp_by_length)){
        printf("ERROR");
        return 0;
    }
     for(unsigned int i=0 ; i<SIZE_OF_INPUT ; i++){
        printf_s("%s,",(char*)(strings[i]));
    
    }
    printf_s("\n");

    //sort by length
    if(ERROR==bubble_sort_letters(strings,SIZE_OF_INPUT ,strcmp)){
        printf("ERROR");
        return 0;
    }
     for(unsigned int i=0 ; i<SIZE_OF_INPUT ; i++){
        printf_s("%s,",(char*)(strings[i]));

    
    }

    return 0;
}
