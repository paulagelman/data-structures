#include <stdlib.h> 
#include<stdio.h>
#define SIZE 34

int convert_string_int(char string_){

}

int check_valid_input(int  length,char string[] ){
    for(int i=0;i<length;i++){
        if('0'>string[i]  || '9'<string[i]){
            printf("not a number");
            return 0;
        }
        return 1;
    }
}

int main()
{
    char string_input[SIZE];
    int number;
    printf("Enter a number");
    scanf("%s",&string_input);
    
    if(!check_valid_input(strlen(string_input),string_input))
        return 0;

    number = atoi(string_input);

    printf("The integer value is: %d\n", number+36);
    return 0;
}
