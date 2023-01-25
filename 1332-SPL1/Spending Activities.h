#include<bits/stdc++.h>
#include "Balance Activities.h";

using namespace std;

int getSpendingType(){
    cout << "Enter spending type: " << endl;
    cout << "\t1. Need" << endl;
    cout << "\t2. Demand" << endl;

    cout << "Your response: ";
    int spendingType;
    cin >> spendingType;
    return spendingType;
}


int getSpendingSource(){
    cout << "\tWhich type of balance?" << endl;
    cout << "\t1. Cash balance" << endl;
    cout << "\t2. Running Account balance" << endl;
    cout << "\t3. Saving Account balance" << endl;
    cout << "\t4. Credit card" << endl;

    cout << "Your response: ";
    int spendingSource;
    cin >> spendingSource;
    return spendingSource;
}

bool checkBalanceIsEnough(float balance, float amount){
    return (amount <= balance);
}

bool savingsPrevent(int spendingSource){
    if(spendingSource == 3){
        cout << "You are not allowed to access your saved money for this purpose." << endl;
        return true;
    }

    return false;
}

void performSpending(int spendingSource, float amount){
    if(spendingSource == 1){
        if(checkBalanceIsEnough(cashBalance, amount) == false){
            cout << "Sorry! You do not have enough balance." << endl;
            return;
        }

        cashBalance += amount;
        printCashBalance();
    }

    if(spendingSource == 2){
        if(checkBalanceIsEnough(runningAccountBalance, amount) == false){
            cout << "Sorry! You do not have enough balance." << endl;
            return;
        }

        runningAccountBalance += amount;
        printRunningAccountBalance();
    }

    return;
}

void spendForNeed(){
    int spendingSource;
    spendingSource = getSpendingSource();

    if(savingsPrevent(spendingSource)) return;

    float amount;
    amount = getAmount();

    if(spendingSource == 4){
        creditCardDebit += amount;
        printCreditCardDebit();
        return;
    }

    performSpending(spendingSource, amount);
    needSpending += amount;

    return;
}

void spendForDemand(){
    int spendingSource;
    spendingSource = getSpendingSource();

    if(savingsPrevent(spendingSource)) return;

    if(spendingSource == 4){
        cout << "You cannot use your credit card for demand purpose. You can use it just for your need." << endl;
        return;
    }

    float amount;
    amount = getAmount();

    performSpending(spendingSource, amount);
    demandSpending += amount;

    return;
}

void spendMoney(){
    int spendingType;
    spendingType = getSpendingType();

    if(spendingType == 1) spendForNeed();
    if(spendingType == 2) spendForDemand();

    return;
}
