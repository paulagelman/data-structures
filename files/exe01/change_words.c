/*------------------------------------------------------
* Filename: change_words.c
* Description: to change words in the file
* Author: Paula Gelman
-------------------------------------------------------*/
#include <stdio.h>

#define WRONG_ARGUMENTS (-1)
#define CANNOT_OPEN_INPUT_FILE (-2)
#define CANNOT_OPEN_OUTPUT_FILE (-3)
#define CANNOT_CLOSE_INPUT_FILE (-4)
#define CANNOT_CLOSE_OUTPUT_FILE (-5)


int new_order(char * file_name , char * target_file){

    int c = 0;
    int rc = 0;

    //open and reading the file('r')
    FILE * fp_in = fopen (file_name, "r");

    if (NULL == fp_in) {
    printf("Could not open %s.\n", file_name);
    return CANNOT_OPEN_INPUT_FILE;
    }

    //open and (can) writing ('w')
    FILE * fp_out = fopen(target_file, "w");

    if (NULL == fp_out) {
    printf("Could not open %s.\n", target_file);
    fclose(fp_in);
    return CANNOT_OPEN_OUTPUT_FILE;
    }

    char ch;
    int lines=0;
    int words=0;
    int letters=0;
    int in_word=0;

    /* scanning the input file */
    while (EOF != (c = fgetc(fp_in))) {
        
        char ch = (char)c;

        //while we in the same line in the file input
        while(ch != '\n'){
            //while we in the same word-we copy 
            while(ch != ' '){
                fputc(ch, fp_out);
                ch = fgetc(fp_in);
            }
            
            //newline in the output file
            fprintf(fp_out , "\n");
        }
            
    }

    /* Close files */
    rc = 0;

    if (0 != fclose(fp_in)) {
    printf("Could not close %s.\n", file_name[1]);
    rc = CANNOT_CLOSE_INPUT_FILE;
    }
    if (0 != fclose(fp_out)) {
    printf("Could not close %s.\n", file_name[2]);
    rc = CANNOT_CLOSE_OUTPUT_FILE;
    }

    return rc;



}
