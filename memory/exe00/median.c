
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

    int *temp_numbers =(int*) realloc(numbers, (i+1) * sizeof(int));

    if(temp_numbers != NULL){
        numbers = temp_numbers;
    }
    else{
        printf("The realloc faild");
    }
}


void sort_array(int *numbers,int size){

    int min;
    for (int i = 0; i < (size - 1); ++i){
        for (int j = 0; j < size - 1 - i; ++j ){
            if (numbers[j] > numbers[j+1]){
                min = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = min;
            }
        }
    }
}


int find_hechion(int *numbers,int size){

    int sum;
    sort_array(numbers, size);

    if(size % 2 == 0){
        sum = numbers[size/2] + numbers[(size/2) + 1];
         return sum/2;
    }
    else{
        sum= numbers[size/2];
        return sum;
    }

}


int main(){

    int hechion;
    int i;
    char check;
    char pause='1';
    int size;
    printf("Enter numbers");
    int *numbers = (int *) malloc(2*sizeof(int));
    scanf("%d",numbers);


    i = 1;
    /* check until the input is not a number or '\n' */
    while ((pause >'0' && pause <'9') || pause =='\n') {
    scanf("%d\n%c", numbers+i , &pause);
    i++;
    make_bigger_arr(numbers,i);
  }

    size = sizeof(numbers);
    hechion = find_hechion(numbers, size);
    
    printf("The hechion is:%d",hechion);

    free(numbers);

    return 0;
}
