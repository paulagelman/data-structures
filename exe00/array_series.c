/*------------------------------------------------------
* Filename: array_series.c
* Description: the program checks if the series is increasing\decreasing\
constant or messed up
* Author: Paula Gelman
-------------------------------------------------------*/
#include <stdio.h>
#define SIZE 15

int main(){

    int prev;
    int curr;
    int is_increasing=1;
    int is_decreasing=1;
    int is_constant=1;

    printf("Enter 15 numbers:\n");
    scanf("%d", &prev);

    for(int i=1; i<SIZE;i++){
        scanf("%d", &curr);

        if(curr!=prev)
            is_constant =0;
        if(curr<=prev)
            is_increasing =0;
        if(curr>=prev)
            is_decreasing=0;
       
        if(!is_increasing && !is_decreasing && !is_constant) {
            printf("The array is messed up");
            return 0;  
        }

        prev=curr;
    }
    if (is_constant)
        printf("The array is constant");
    else if (is_increasing)
        printf("The array is increasing");
    else if (is_decreasing)
        printf("The array is decreasing");

    return 0;
}
