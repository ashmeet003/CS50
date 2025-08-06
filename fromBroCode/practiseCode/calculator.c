/*The program aims to create a calculator program
Getting user input as operator needs to be used and 
use switch statement to calculate*/

#include <stdio.h>

int main(void){
    char operator='\0';
    double num1=0.0;
    double num2=0.0;
    double result=0.0;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the operator (+ - * /): ");
    scanf(" %c", &operator);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operator){
        case '+':
            result= num1 + num2;
            printf("%lf %c %lf = %lf", num1, operator, num2, result);
            break;
        case '-':
            result= num1 - num2;
            printf("%lf %c %lf = %lf", num1, operator, num2, result);
            break;
        case '*':
            result= num1 * num2;
            printf("%lf %c %lf = %lf", num1, operator, num2, result);
            break;
        case '/':
            result= num1 / num2;
            printf("%lf %c %lf = %lf", num1, operator, num2, result);
            break;
        default:
            printf("Invalid operator!");
            break;
    }
}