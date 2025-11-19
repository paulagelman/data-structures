/*------------------------------------------------------
* Filename: file_operations.c
* Description: use operations on files
* Author: Paula Gelman
-------------------------------------------------------*/


/*
תיקונים לפי פונקציה:

על מנת שlines לא יהיה 0 במקרה של שורה אחת print_file_lenght

print_file_length עשיתי השמה לתו ch לכן תקין כעת

שיניתי את כל הFILE[i]

בcopy_file הוספתי בדיקת שגיאה ל-fputc

תיקנתי הזחות shift בקובץ:)
*/


#include <stdio.h>

#define WRONG_ARGUMENTS (-1)
#define CANNOT_OPEN_INPUT_FILE (-2)
#define CANNOT_OPEN_OUTPUT_FILE (-3)
#define CANNOT_CLOSE_INPUT_FILE (-4)
#define CANNOT_CLOSE_OUTPUT_FILE (-5)

/*------------------------------------------------------
* Function Name - print_file
*
* Function Purpose - to print the text in the file
*
* Parameters – char *file_name

* Return Values - The rc(flag for us to know if the closing worked)
*
* Author - Gelman Paula
-------------------------------------------------------*/
int print_file( char *file_name) {

    //open and reading the file('r')
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("could not open %s.\n", file_name);
        return CANNOT_OPEN_INPUT_FILE;
    }

    int ch = 0;
    while (EOF != (ch = fgetc(file)) ) { //scan the file till the end
        putchar(ch); //print
    }

    int rc = 0;
    if (0 != fclose(file)) {
    printf("Could not close %s.\n", file_name);
    rc = CANNOT_CLOSE_INPUT_FILE;
    }

return rc;
}

/*------------------------------------------------------
* Function Name - copy_file
*
* Function Purpose - to copy file's text to the target file
*
* Parameters – char * file_name , char * target_file

* Return Values - The rc(flag for us to know if the closing worked)
*
* Author - Gelman Paula
-------------------------------------------------------*/


/*we saw it in the course book*/
int copy_file(char * file_name , char * target_file)
{
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

    /* Copy contents */
    while (EOF != (c = fgetc(fp_in))) {

        if (fputc(ch, fp_out) == EOF) {
        perror("fputc failed");
        fclose(fp_in);
        fclose(fp_out);
        return CANNOT_OPEN_OUTPUT_FILE; 
        }

        fputc(c, fp_out);

    }
    /* Close files */
    rc = 0;

    if (0 != fclose(fp_in)) {
        printf("Could not close %s.\n", file_name);
        rc = CANNOT_CLOSE_INPUT_FILE;
    }
    if (0 != fclose(fp_out)) {
        printf("Could not close %s.\n", target_file);
        rc = CANNOT_CLOSE_OUTPUT_FILE;
    }

    return rc;
}

/*------------------------------------------------------
* Function Name - print_file_lenght
*
* Function Purpose - to print file's number of lines,words and letters
*
* Parameters – char * file_name 

* Return Values - The rc(flag for us to know if the closing worked)
*
* Author - Gelman Paula
-------------------------------------------------------*/
int print_file_lenght( char *file_name) {

    FILE *file = fopen(file_name, "r"); 
    if (file == NULL) {
        printf("could not open %s.\n", file_name);
        return CANNOT_OPEN_INPUT_FILE;
    }

    int rc=0;
    int c = 0;
    char ch;
    int lines=0;
    int words=0;
    int letters=0;
    int in_word=0;

        /* scanning the file */
    while (EOF != (c = fgetc(file))) {

            char ch = (char)c;
            
            if (char!=NULL)
                lines++;

            if (ch!=' ' && ch!='\n' && ch!='\t')
                letters++;

        /*space,\n,\t :means that we are not in the word */
            if (ch ==' ' || ch =='\n' || ch =='\t') {
                in_word = 0; 
                lines++;
            } else if (in_word == 0) {
                in_word = 1; // new word
                words++;
            }  

        /* '\n' is a sign to new line*/
            if (ch == '\n')
                lines++;

    

       
    }
    printf("%d",lines);
    printf("%d",words);
    printf("%d",letters);

    rc = 0;
    if (0 != fclose(file)) {
        printf("Could not close %s.\n", file_name);
        rc = CANNOT_CLOSE_INPUT_FILE;
    }

    return rc;
}


/*------------------------------------------------------
* Function Name -delete_line
*
* Function Purpose - to delete given line from the file
*
* Parameters –char *file_name,int line_to_delete

* Return Values - The rc(flag for us to know if the closing worked)
*
* Author - Gelman Paula
-------------------------------------------------------*/
int delete_line(char *file_name,int line_to_delete){

     FILE *file = fopen(file_name, "r"); 
    if (file == NULL) {
        printf("could not open %s.\n", file_name);
        return CANNOT_OPEN_INPUT_FILE;
    }

     FILE *temp = fopen("temp.txt", "w");
     if (temp == NULL) {
        printf("could not open %s.\n", file_name);
        return CANNOT_OPEN_INPUT_FILE;
    }

    int current_line=1;
    char line[200];/*200 is good enough*/
     while (fgets(line, sizeof(line), file)) {
        if (current_line != line_to_delete) {
            fputs(line, temp);  // copy all the lines except for the deleted one
        }
        current_line++;
    }

    
    int rc = 0;

    if (0 != fclose(file)) {
        printf("Could not close %s.\n", file_name);
        rc = CANNOT_CLOSE_INPUT_FILE;
    }
    if (0 != fclose(temp)) {
        printf("Could not close %s.\n", file_name);
        rc = CANNOT_CLOSE_OUTPUT_FILE;
    }

return rc;
}
