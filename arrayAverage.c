//Program works to have an array of N number
//ask for user input for numbers and have it average

#include <stdio.h>
float average(int length, int arr[]);
const int N = 3;
int main(void){
    int array[N];
    int num;
    for(int i=0;i<N;i++){
        printf("Enter number you want to use for average: ");
        scanf("%d", &num);
        array[i]=num;
    }
    float avrge;
    avrge = average(N, array);
    printf("The average of numbers: %f", avrge);

}

float average(int length, int arr[]){
    float sum;
    for(int i=0;i<length;i++){
        sum+=arr[i];
    }
    return (sum/3);
}