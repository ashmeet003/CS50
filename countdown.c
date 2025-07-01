/*Program intends to create a countdown
  with delay of 1 second*/

#include <stdio.h>
#include <windows.h> //header file for windows
// <unistd.h> for mac or linux

int main(void){
    printf("Countdown begins!\n");

    for(int i=10; i>0; i--){
        printf("%d\n", i);
        Sleep(1000); //1000 ms = 1s
        //sleep() for mac/linux with small s
    }
    
    printf("Happy New Year!!!!\n");
}