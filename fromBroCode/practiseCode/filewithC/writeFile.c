/*This program shows to write a file in c*/
#include <stdio.h> //contains inbuilt struct FILE

int main(){

    FILE *pFile = fopen("output.txt", "w"); //w = write, a = append, & r = read
    char text[] = "This is written in file.\nHave a good day!!!\n";
    int numText = 123456;

    if(pFile == NULL){ //checks if file was created
        printf("File couldn't be opened!\n");
        return 1;
    }

    printf("File was opened successfully!\n");
    fprintf(pFile, "%s", text); //prints text in file
    fprintf(pFile, "%d", numText);

    fclose(pFile); //file must be closed

    return 0;
}