//#include <stdlib.h>
#include <stdio.h> //standard io header file
//header file : contains functionality which comes with the language
// gives access to libraries
int main(void)
{
    //string answer=get_string("whats your name? ");
    //printf("hello, world. Name is %s\n", answer);
    char name[100];
    printf("hello, world.\nWhat is your name?\n");
    scanf("%s", name);
    printf("Hello, my name is %s\n",name);
}