/*------------------------------------------------------
* Filename: array_sort.c
* Description: 
* Author: Paula Gelman
-------------------------------------------------------*/


#include <stdio.h>
#include <string.h>
#define SIZE 10


/*------------------------------------------------------
* Function Name - init_pointers
*
* Function Purpose - Make the pointer array point to the 
array of numbers
* Parameters – int arr[],int *pointers[],int size
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void init_pointers(int arr[],int *pointers[],int size){

    for(int i=0;i<size;i++){
        pointers[i]=&(arr[i]);
    }

}


/*------------------------------------------------------
* Function Name - swap_pointers
*
* Function Purpose -swap pointers by their value
* Parameters – int arr[],int *pointers[],int size
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void swap_pointers(int arr[],int *pointers[],int size){

    for(int i=0;i<size;i++){
        for(int j=i;j<size-1;j++){
            
            if(*pointers[j+1]<*pointers[i]){
               int *temp_pointer=pointers[j+1];
                pointers[j+1]=pointers[i];
                pointers[i]=temp_pointer;
            }
        }
    }

}

int main(){

    int int_arr[SIZE];
    int *pointers_to_int[SIZE];


    printf("Enter 10 numbers");

    for(int i=0;i<SIZE;i++){
        scanf("%d",&int_arr[i]);
    }

    init_pointers(int_arr,pointers_to_int,SIZE);

    for(int j=0;j<SIZE;j++){
    printf("value:%d,addres:%p\n",*pointers_to_int[j],pointers_to_int[j]);
    }

    swap_pointers(int_arr,pointers_to_int,SIZE);

    for(int j=0;j<SIZE;j++){
    printf("value:%d,addres:%p\n",*pointers_to_int[j],pointers_to_int[j]);
    }



    return 0;
}
