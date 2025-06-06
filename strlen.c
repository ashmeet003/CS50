//Checks length of a string

#include <stdio.h>
int strlen( char *str);
void toUpperCase(char *str);

int main(void){
    char stri[50];
    printf("Enter a string: ");
    scanf("%s", stri);
    //further are function outputs
    printf("Length of string is: %d\n", strlen(stri));
    toUpperCase(stri);
    printf("Upper case version of string: %s", stri);
}

int strlen(char *str){ //returns length of the string
    int n=0;
    while(str[n]!='\0'){
        n++;
    }
    return n;
}

void toUpperCase(char *str){ //string is changed at memory so no return value
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
    }
}
