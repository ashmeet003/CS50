//Checks length of a string

#include <stdio.h>
#include <stdbool.h>
int strlen( char *str); //returns length of the string
void toUpperCase(char *str); //string is changed at memory so no return value
bool isletter(char *str); //checks if string has char other than letters

int main(void){
    char stri[50];
    printf("Enter a string: ");
    scanf("%s", stri);
    //further are function outputs
    printf("Length of string is: %d\n", strlen(stri));
    toUpperCase(stri);
    printf("Upper case version of string: %s\n", stri);
    bool letterFlag= isletter(stri);
    if(letterFlag==1){
        printf("All chars are letters.\n");
    }
    else{
        printf("String includes char other than letters.\n");
    }
}

int strlen(char *str){ //returns length of the string
    int n=0;
    while(str[n]!='\0'){
        n++;
    }
    return n;
}

void toUpperCase(char *str){ //string is changed at memory so no return value
    /*instead of following if statement a function called toupper() could also be used.
        It would need <ctype.h> header file.*/
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
    }
}

bool isletter(char *str){ //checks if string has char other than letters
    for(int i=0;str[i]!='\0';i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) ){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}