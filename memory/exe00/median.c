
/*------------------------------------------------------
* Filename: median.c
* Description: 
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

int main(){

    int i;
    char check;
    char pause='8';
    printf("Enter numbers");
    int *numbers = (int *) malloc(2*sizeof(int));
    scanf("%d",numbers);


    i = 1;
    /* check until the input is not a number or '\n' */
    while ((pause >'0' && pause <'9') || pause =='\n') {
    scanf("%d\n%c",numbers+i,&pause);
    i++;
    make_bigger_arr(numbers,i);
  }

    for(int j=0;j<i;j++){
        printf("%d\n",numbers[j]);
    }
    

     free(numbers);

    return 0;
}
