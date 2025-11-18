/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: print values and addreses
* Author: Paula Gelman
-------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#define SIZE 8

int main() {

    int numbers[SIZE];
    char chars[SIZE];
    int *temp_numbers= numbers;
    char *temp_chars= chars;

    printf("Enter numbers:\n");
    for(int i=0;i<SIZE;i++){
        scanf("%d",&numbers[i]);
    }

    printf("Enter chars:\n");
    for(int k=0;k<SIZE;k++){
        scanf(" %c",&chars[k]);
    }


    /*using [] operator*/
    for(int j=0;j<SIZE;j++){
    printf("value:%d,addres:%p\n",numbers[j],(void *)&numbers[j]);
    }
    /*using * operator*/
     for(int j=0;j<SIZE;j++){
    printf("value:%d,addres:%p\n",*(temp_numbers+j),(void *)(temp_numbers+j));
    }


    /*using [] operator*/
    for(int j=0;j<SIZE;j++){
    printf("value:%c,addres:%p\n",chars[j],(void *)&chars[j]);
    }
    /*using * (pointer) operator*/
    for(int j=0;j<SIZE;j++){
    printf("value:%c,addres:%p\n",*(temp_chars+j),(void *)(temp_chars+j));
    }



    return 0;
}
