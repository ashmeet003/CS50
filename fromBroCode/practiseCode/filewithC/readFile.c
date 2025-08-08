/*This program shows how to read file from a file using absolute path*/
#include <stdio.h>

int main(){

    FILE *pFile = fopen("C:\\Users\\aishx\\Documents\\selfStudy\\CS50\\fromBroCode\\practiseCode\\filewithC\\readFile.txt", "r");
    char buffer[1024] = {0}; //to store file text using 1024 bytes

    if(pFile == NULL){
        printf("File couldn't be opened\n");
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    fclose(pFile);

    return 0;
}