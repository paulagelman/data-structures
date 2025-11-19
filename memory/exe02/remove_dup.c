/*------------------------------------------------------
* Filename: remove_dup.c
* Description: to copy the array to dynamic one
* Author: Paula Gelman
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------
* Function Name - make_bigger_arr
*
* Function Purpose - Make the array bigger in one element
* Parameters – int *numbers,int i
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void make_bigger_arr(int *numbers,int i){

    int *temp_numbers =(int*)realloc(numbers, (i+1)*sizeof(int));
    if(temp_numbers!=NULL){
    numbers=temp_numbers;
    }
    else{
        printf("The realloc faild");
    }
}

/*------------------------------------------------------
* Function Name - remove_dup
*
* Function Purpose - to remove duplicate number

* Parameters –int *arr
*
* Return Values - address of the dynamic array
*
* Author - Gelman Paula
-------------------------------------------------------*/
int remove_dup(int *arr){

    int size=sizeof(arr);
    int *numbers = (int *) malloc(sizeof(int));
    int number;

    int *arr_one_show = (int *) malloc(2*sizeof(int));

    int j=0;
    for(int i=1 ; i<size ; i++){
        number=arr[i];
        if(arr_one_show[j]!=number){
            arr_one_show[j+1]=number;
            j++;
            make_bigger_arr(arr_one_show,j+1);
        }

        return arr_one_show[0];
       
            
    }
    
}




int main(){

    int numbers[10]={1,1,1,2,3,3,3,4,5,5};
    int addres=remove_dup(numbers);
    printf("the addres of the dynamic arrray is:%d\n",&addres);


    return 0;
}
