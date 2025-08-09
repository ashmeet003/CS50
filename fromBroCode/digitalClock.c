/*
    This program is designed to create a digital clock.
    Mainly using <time.h> file and its functions
*/
#include <stdio.h>
#include <time.h>
#include <windows.h> //contains sleep()
#include <stdbool.h> //for bool

int main(){

    time_t rawtime = 0; // time_t data type hold seconds from Unix Epoch: Jan 1, 1970
    struct tm *pTime = NULL; //built in struct in <time.h> pointer specified as NULL; prevents garbage value
    bool isRunning = true;

    printf("DIGITAL CLOCK:\n");
    while(isRunning){ //runs till true

        time(&rawtime); //restamps the rawtime with current local machine time
        pTime = localtime(&rawtime); //returns pointer to time pointer with hr/min/sec values
        printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec); //pTime->tm_hour == (*pTime).tm_hour; dereferencing pointer and then accessing the variable
        //\r return cursor back to first place hence rewriting the print statement
        Sleep(1000); //delays program with 1 second
    }

    return 0;
}