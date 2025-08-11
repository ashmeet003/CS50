#include <stdio.h>

    void checkCash();
    void checkCreditCard();

int main(){

    int option;
    printf("Enter option 1 for cash and option 2 for card check: ");
    scanf("%d", &option);
    if(option == 1){
        checkCash();
    }
    if(option == 2){
        checkCreditCard();
    }
    
    return 0;
}

void checkCash(){
    int owed = 0;
    
    do{
        printf("Cash owed: cents");
        scanf("%d", &owed);
        if(owed < 0){
            printf("Invalid input! Please enter a positive value.\n");
        }
    }while(owed < 0);

    int totalCount = 0;
    int coinsUsed = 0;

    if(owed >= 25){
        coinsUsed = owed / 25;
        owed = owed % 25;
        totalCount += coinsUsed;
    }
    if(owed >= 10){
        coinsUsed = owed / 10;
        owed = owed % 10;
        totalCount += coinsUsed;
    }
    if(owed >= 5){
        coinsUsed = owed / 5;
        owed = owed % 5;
        totalCount += coinsUsed;
    }
    if(owed >= 1){
        coinsUsed = owed;
        totalCount += coinsUsed;
    }
    printf("Coins Needed: %d", totalCount);
}

void checkCreditCard(){
    char cardNum[16];
    printf("Please Enter a card Number: ");
    scanf("%s", &cardNum);
    //printf("%s",  cardNum);

    int isCheck;

    int strLen=0;
    while(cardNum[strLen]!='\0'){
        strLen++;
    } 

    int position = 1;
    int addOdds = 0, addEvens = 0;
    for(int i = strLen-1; i >= 0; i--){

        if(position % 2 == 0){
            int product = 0;
            product = ((cardNum[i] - '0')*2);
            if(product > 9){
                addEvens += ((product % 10) + 1);
            }
            else{
                addEvens += product;
            }
        }
        else{
            addOdds += (cardNum[i] - '0');
        }
        position++;
    }

    int sum = addEvens + addOdds;
    isCheck = sum % 10;
    if(isCheck != 0){
        printf("Invalid card Input\n");
    }
    else{
        int twoDigits = 0;
        //char oneDigit[2];
        //oneDigit[0] = cardNum[0];
        //oneDigit[1] = '\0';
        twoDigits = (cardNum[0] - '0');
        twoDigits = (twoDigits*10) + (cardNum[1] - '0');
        //twoDigits[2] = '\0';

        //printf(">> %s", twoDigits);
        if(twoDigits == 34 || twoDigits == 37){
            printf("AMEX\n");
        }
        if(twoDigits == 51 || twoDigits == 52 || twoDigits == 53 || twoDigits == 54 || twoDigits == 55){
            printf("MASTERCARD\n");
        }
       //printf("%c", cardNum[0]);
       
        if((cardNum[0]) == '4'){
            printf("VISA\n");
        }
    }


}