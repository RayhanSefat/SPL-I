#include<bits/stdc++.h>
#include "Print.h";

float getAmount(){
    cout << "Enter amount: ";
    float amount;
    cin >> amount;

    return amount;
}

int getBalanceType(){
    cout << "\tWhich type of balance?" << endl;
    cout << "\t1. Cash balance" << endl;
    cout << "\t2. Running Account balance" << endl;
    cout << "\t3. Saving Account balance" << endl;

    cout << "Your response: ";
    int balanceType;
    cin >> balanceType;
    return balanceType;
}

void addBalance(){
    int balanceType;
    balanceType = getBalanceType();

    float amount = getAmount();

    if(balanceType == 1){
        cashBalance += amount;
        printCashBalance();
    }

    if(balanceType == 2){
        runningAccountBalance += amount;
        printRunningAccountBalance();
    }

    if(balanceType == 3){
        savingAccountBalance += amount;
        printSavingAccountBalance();
    }

    return;
}

int getTransferType(){
    cout << "Transfer options: " << endl;
    cout << "\t1. Running account balance to cash balance" << endl;
    cout << "\t2. Cash balance to saving account balance" << endl;
    cout << "\t3. Running account balance to saving balance" << endl;
    cout << "\t4. Saving account balance to cash balance" << endl;

    cout << "Your response: ";
    int transferType;
    cin >> transferType;
    return transferType;
}

void transferBalance(){
    int transferType;
    transferType = getTransferType();

    float amount = getAmount();

    if(transferType == 1){
        if(amount > runningAccountBalance){
            cout << "Sorry! You don't have sufficient balance in your running account." << endl;
            return;
        }

        runningAccountBalance -= amount;
        cashBalance += amount;

        printRunningAccountBalance();
        printCashBalance();
    }

    if(transferType == 2){
        if(amount > cashBalance){
            cout << "Sorry! You don't have sufficient balance in cash." << endl;
            return;
        }

        cashBalance -= amount;
        savingAccountBalance += amount;
        savedAmount += amount;

        printCashBalance();
        printSavingAccountBalance();
    }

    if(transferType == 3){
        if(amount > runningAccountBalance){
            cout << "Sorry! You don't have sufficient balance in your running account." << endl;
            return;
        }

        runningAccountBalance -= amount;
        savingAccountBalance += amount;
        savedAmount += amount;

        printRunningAccountBalance();
        printSavingAccountBalance();
    }

    if(transferType == 4){
        if(amount > savingAccountBalance){
            cout << "Sorry! You don't have sufficient balance in your saving account." << endl;
            return;
        }

        savingAccountBalance -= amount;
        cashBalance += amount;

        printSavingAccountBalance();
        printCashBalance();
    }

    return;
}
