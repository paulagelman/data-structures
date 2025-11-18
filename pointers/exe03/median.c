
/*------------------------------------------------------
* Filename: median.c
* Description: 
* Author: Paula Gelman
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

void make_bigger_arr(int *numbers,int i){

    numbers= realloc(numbers, i*sizeof(int));
}

int main(){

    int i=2;
    char check;
    int flag=0;
    printf("Enter numbers");
    int *numbers = (int *) malloc(i*sizeof(int));
    scanf("%d",&numbers[0]);
    int temp_num=*numbers;



    while(flag!=-1)
    {
        scanf("%d",&numbers[i]);
        check = getchar(); 
        if ( (check>39 && check<48)  && check!=10) { /*its not a number */ 
            flag=-1;

        }
        i++;
        make_bigger_arr(numbers,i);

    }

    for(int j=0;j<sizeof(numbers);j++){
        printf("%d\n",numbers[i]);
    }
    

        
    
    


    return 0;
}
