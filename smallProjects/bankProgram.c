/*To create bank program in c:
user will be given option to choose from:
check balance, deposit money, withdraw money, and exit
The program uses pointers and memory to update the user balance throughout the func*/

#include <stdio.h>

void checkBalance(double balance);
void depositMoney(double *balance);
void withdrawMoney(double *balance);

int main(void){
    int option=0;
    double balance = 1000.00;
    printf("****** Welcome to the Bank ******\n");
    do{
        printf("\nSelect an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("You chose to check Balance\n");
                checkBalance(balance);
                break;
            case 2:
                printf("You chose to Deposit Money\n");
                depositMoney(&balance);
                break;
            case 3:
                printf("You chose to Withdraw Money\n");
                withdrawMoney(&balance);
                break;
            case 4:
                printf("You chose to exit the options\n");
                break;
            default:
                printf("Invalid Option! Enter between 1-4.\n");
                break;
        }
    }while(option!=4); //the loop would continue till the user chooses to exit

    printf("\n****** Thank you for using Bank ******\n");
    
}

void checkBalance(double balance){ //a simple display of balance
    printf("\nYour current Balance is : $%.2lf\n", balance);
}

void depositMoney(double *balance){ //money is deposited if > 0.01 and balance is updated at memory
    double depositAmount = 0.00;
    do{
        printf("Enter the amount you wish to deposit: ");
        scanf("%lf", &depositAmount);
        if(depositAmount < 0.01){
            printf("%lf", depositAmount);
            printf("Please enter a value greater than 0! Try again.\n");
        }
    }while(depositAmount < 0.01);

    //updates the memory and shows balance again
    double newmoney = *balance + depositAmount;
    *balance = newmoney;
    checkBalance(*balance);
}

void withdrawMoney(double *balance){ //withdraws money if within balance and updates the remaining balance
    double withdrawAmount = 0.00;
    do{
        printf("Enter the amount you wish to withdraw : $");
        scanf("%lf", &withdrawAmount);
        if(withdrawAmount < 0.01 || withdrawAmount > *balance){
            printf("Invalid Amount! Please enter an amount within 0 and your balance - $%.2lf\n", *balance);
        }
        else{
            printf("Withdraw successful!\n");
        }
    }while(withdrawAmount < 0.01 || withdrawAmount > *balance);

    //updates memory for variable 'balance'
    double newmoney = *balance - withdrawAmount;
    *balance = newmoney;
    checkBalance(*balance);
}