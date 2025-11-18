/*------------------------------------------------------
* Filename: const_pointer.c
* Description: 
* Author: Paula Gelman
-------------------------------------------------------*/


#include <stdio.h>
#include <string.h>

int main(){

    const int channel=3;
    int gili_channel;
    int *new_channel=NULL;

    printf("The channel is %d\n",channel);
    printf("Gili enter channel's number\n");
    scanf("%d",&gili_channel);
    new_channel=(int *)&channel;
    *new_channel=gili_channel;

    printf("The channel is %d\n",channel);




    return 0;
}
