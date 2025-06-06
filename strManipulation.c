//Checks length of a string

#include <stdio.h>
int strlen( char *str);
void toUpperCase(char *str);
int isletter(char *str);

int main(void){
    char stri[50];
    printf("Enter a string: ");
    scanf("%s", stri);
    //further are function outputs
    printf("Length of string is: %d\n", strlen(stri));
    toUpperCase(stri);
    printf("Upper case version of string: %s\n", stri);
    int letterFlag= isletter(stri);
    if(letterFlag==0){
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
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
    }
}

int isletter(char *str){
    int flag=0;
    for(int i=0;str[i]!='\0';i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) ){
            continue;
        }
        else{
            flag=1;
            break;
        }
    }
    return flag;
}