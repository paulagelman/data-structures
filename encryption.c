/*------------------------------------------------------
* Filename: encryption.c
* Description: 
* Author: Paula Gelman
-------------------------------------------------------*/
#include<stdio.h>
#define SIZE 26
#define SHIFT_OF_FIVE 5
#define SHIFT_OF_FOUR 4
#define MULTIPLICATION_BY_SEVEN 7

/*------------------------------------------------------
* Function Name - convert_ascii
*
* Function Purpose - To convert numbers to their ascii char
*
* Parameters – int number
*
* Return Values - return char
*
* Author - Gelman Paula
-------------------------------------------------------*/
char convert_ascii(int number){
    return (char)number;
 
}

/*------------------------------------------------------
* Function Name - swap_half
*
* Function Purpose - To swap half of the array
*
* Parameters – int numbers[]
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void swap_half(int numbers[]){
    
    for (int i=0;i<(SIZE/2);i++){
        int temp=numbers[i];
        numbers[i]=numbers[i + SIZE/2];
        numbers[i +SIZE/2]=temp;
    }
}

/*------------------------------------------------------
* Function Name - delte_previous
*
* Function Purpose - To sub the value of the previous number
 in the array
*
* Parameters – int numbers[]
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void delte_previous(int numbers[]){
    for (int i= SIZE-1;i>0;i--){
        numbers[i]-=numbers[i-1];
    }
}

/*------------------------------------------------------
* Function Name - move_five_forward
*
* Function Purpose - To move the array's values five index 
forward
*
* Parameters – int numbers[]
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void move_five_forward(int numbers[]){
    int i;
    int temp_five_last_items[SHIFT_OF_FIVE];

    for (i=0;i<SHIFT_OF_FIVE;i++){
        temp_five_last_items[i]=numbers[SIZE-SHIFT_OF_FIVE+i];
    }

    for (i=SIZE-SHIFT_OF_FIVE-1;i>=0;i--){
        numbers[i+SHIFT_OF_FIVE]=numbers[i];
    }

    for (i=0; i<SHIFT_OF_FIVE;i++){
        numbers[i]=temp_five_last_items[i];
    }
}

/*------------------------------------------------------
* Function Name - move_four_backward
*
* Function Purpose - To move the array's values four index 
backward
*
* Parameters – int numbers[]
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void move_four_backward(int numbers[]){
    int i;
    int temp_first_items[SHIFT_OF_FOUR];

    for (i=0;i<SHIFT_OF_FOUR;i++){
        temp_first_items[i] = numbers[i];
    }

    for (i = 0; i < SIZE - SHIFT_OF_FOUR; i++){
        numbers[i]=numbers[i+SHIFT_OF_FOUR];
    }

    for (i =0;i<SHIFT_OF_FOUR;i++){
        numbers[SIZE-SHIFT_OF_FOUR+i] =temp_first_items[i];
    }
}

/*------------------------------------------------------
* Function Name - decreasing_by_five
*
* Function Purpose - To decreas array's value byfive
*
* Parameters – int numbers[]
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void decreasing_by_five(int numbers[]){
    for(int i=0;i<SIZE;i++){
        numbers[i]-=5;
    }

}


/*------------------------------------------------------
* Function Name - even_index
*
* Function Purpose - To divide even index by seven
*
* Parameters – int numbers[]
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void even_index(int numbers[]){

    for(int i=0;i<SIZE;i+=2){
        numbers[i]=numbers[i]/MULTIPLICATION_BY_SEVEN;
    }
}




int main(){

    int numbers[SIZE]={0};
    char massage[SIZE+1];

    printf("Gargamel enter the numbers");
     for(int j=0;j<SIZE;j++){
        scanf("%d",&numbers[j]);
    }


    swap_half(numbers);
    delte_previous(numbers);
    move_five_forward(numbers);
    even_index(numbers);
    move_four_backward(numbers);
    decreasing_by_five(numbers);


    for (int i = 0; i < SIZE; i++)
    printf("%d ", numbers[i]);
    printf("\n");


    for(int i=0;i<SIZE;i++){
       massage[i]=convert_ascii(numbers[i]);
    }

    for (int i=0; i<SIZE;i++)
        printf("%c", massage[i]);

    return 0;

}
