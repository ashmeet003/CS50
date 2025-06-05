//Checks length of a string
#include <stdio.h>
int main(void){
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    int n=0;
    while(str[n]!='\0'){
        n++;
    }
    printf("Length of string is: %d", n);
    
}