/*------------------------------------------------------
* Filename: array_series.c
* Description: the program checks if the series is increasing\decreasing\
constant or messed up
* Author: Paula Gelman
-------------------------------------------------------*/
#include <stdio.h>

/*------------------------------------------------------
* Function Name - check_increasing_series
*
* Function Purpose - To check is the given series is increasing
*
* Parameters – int series[]
*
* Return Values - return 1 if increasing,else return 0
*
* Author - Gelman Paula
-------------------------------------------------------*/
int check_increasing_series(int series[]){
    for(int i=0;i<14;i++){
        if(series[i]>series[i+1])
            return 0;    
    }
    return 1;
}

/*------------------------------------------------------
* Function Name - check_decreasing_series
*
* Function Purpose - To check is the given series is idecreasing
*
* Parameters – int series[]
*
* Return Values - return 1 if decreasing,else return 0
*
* Author - Gelman Paula
-------------------------------------------------------*/
int check_decreasing_series(int series[]){
    for(int i=0;i<14;i++){
        if(series[i]<series[i+1])
            return 0;    
    }
    return 1;
}

/*------------------------------------------------------
* Function Name - check_constant_series
*
* Function Purpose - To check is the given series is constant
*
* Parameters – int series[]
*
* Return Values - return 1 if constant,else return 0
*
* Author - Gelman Paula
-------------------------------------------------------*/
int check_constant_series(int series[]){
    for(int i=0;i<14;i++){
        if(series[i]!=series[i+1])
            return 0;    
    }
    return 1;
}



int main() {
    
    int series[15];
    printf("Enter 15 numbers");

    for(int j=0;j<15;j++){
        scanf("%d",&series[j]);
    }

   if(check_constant_series(series)==1){
    printf("The array is constant");
   } 
   else{
    if(check_decreasing_series(series)==1){
        printf("The array is decreasing");}
    else{
    if(check_increasing_series(series)==1)
         printf("The array is increasing");
    else
        printf("The array is messed up");

}
   }
 return 0;
}
