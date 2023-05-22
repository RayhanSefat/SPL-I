#include<bits/stdc++.h>
#include "File Read and Write.h";

void printRunningAccountBalance(){
    cout << "Your current running account balance: " << runningAccountBalance << endl;
    return;
}

void printSavingAccountBalance(){
    cout << "Your current saving account balance: " << savingAccountBalance << endl;
    return;
}

void printCashBalance(){
    cout << "Your current cash balance: " << cashBalance << endl;
    return;
}

void printCreditCardDebit(){
    cout << "Your current credit card credit balance: " << creditCardDebit << endl;
    return;
}

void printTotalShrePrioces(){
    float totalSharePrice = 0.0;

    for(int i=0; i<numberOfCompanies; i++){
        totalSharePrice += sharePrize[i];
    }

    cout << "Your share market worth: " << totalSharePrice << endl;

    return;
}
