/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: to make dynamic struct for Time
* Author: Paula Gelman
-------------------------------------------------------*/
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MIN 60

#include <stdio.h>
#include <stdlib.h>

struct Time {
int hours;
int min;
int sec;
};

/*------------------------------------------------------
* Function Name - add_time
*
* Function Purpose - To sum 2 times
*
* Return Values - struct Time*
*
* Author - Gelman Paula
-------------------------------------------------------*/
struct Time* add_time(struct Time *time1,struct Time *time2){

    int sec;
    int min;

    struct Time *total_time = (struct Time*)malloc(sizeof(struct Time));
    total_time->hours = time1->hours + time2->hours;
    total_time->min = time1->min + time2->min;
    total_time->sec = time1->sec + time2->sec;

    /*in case there are more then 60 sec/min */
    if(total_time->sec>SECONDS_IN_MIN){
        sec= (total_time->sec)/SECONDS_IN_MIN;
        total_time->sec = total_time->sec - (sec*SECONDS_IN_MIN);
         total_time->min+=sec;
    }

    if(total_time->min>MINUTES_IN_HOUR){
        min= (total_time->min)/MINUTES_IN_HOUR;
        total_time->min = total_time->min - (min*MINUTES_IN_HOUR);
         total_time->hours+=min;
    }

return total_time;

}

int main(){

    struct Time *first_time = (struct Time*)malloc(sizeof(struct Time));
    struct Time *second_time = (struct Time*)malloc(sizeof(struct Time));


    printf("Enter first:hours,minutes and seconds\n");
    scanf("%d",&first_time->hours);
    scanf("%d",&first_time->min);
    scanf("%d",&first_time->sec);

    printf("Enter second:hours,minutes and seconds\n");
    scanf("%d",&second_time->hours);
    scanf("%d",&second_time->min);
    scanf("%d",&second_time->sec);

    struct Time *sum=add_time(first_time,second_time);

     printf("The sum of times is:hours: %dminutes:%dseconds:%d\n",
           sum->hours, sum->min, sum->sec);

    free(first_time);
    free(second_time);
    free(sum);
    return 0;

}
