#include<bits/stdc++.h>

using namespace std;

fstream fptr3;

//these variables are taken globally to take input once and use for several operations
float cashBalance;
float runningAccountBalance;
float savingAccountBalance;
float savingAccountInteresfRate;
int numberOfCompanies;
float sharePrize[1001];
float creditCardDebit;

void takeInputFromTheBalanceInformationSheet(){
    fptr3.open("Balance Information.txt");

    fptr3 >> cashBalance;
    fptr3 >> runningAccountBalance;
    fptr3 >> savingAccountBalance;
    fptr3 >> savingAccountInteresfRate;
    fptr3 >> numberOfCompanies;
    for(int i=1; i<=numberOfCompanies; i++){
        fptr3 >> sharePrize[i];
    }
    fptr3 >> creditCardDebit;

    fptr3.close();

    return;
}

void updateTheBalanceInformationSheet(){
    fptr3.open("Balance Information.txt");

    fptr3 << cashBalance << endl;
    fptr3 << runningAccountBalance << endl;
    fptr3 << savingAccountBalance << endl;
    fptr3 << savingAccountInteresfRate << endl;
    fptr3 << numberOfCompanies << endl;
    for(int i=1; i<=numberOfCompanies; i++){
        fptr3 << sharePrize[i] << endl;
    }
    fptr3 << creditCardDebit << endl;

    fptr3.close();

    return;
}

bool repeatationChecker()
{
    cout << "Do you want to conduct one more operation?" << endl;
    cout << "\t1. Yes" << endl;
    cout << "\t2. No" << endl;

    int repeatingCommand;
    cin >> repeatingCommand;

    if(repeatingCommand == 1) return true;
    return false;
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

float getAmount(){
    cout << "Enter amount: ";
    float amount;
    cin >> amount;

    return amount;
}

void printCashBalance(){
    cout << "Your current cash balance: " << cashBalance << endl;
    return;
}

void printRunningAccountBalance(){
    cout << "Your current running account balance: " << runningAccountBalance << endl;
    return;
}

void printSavingAccountBalance(){
    cout << "Your current saving account balance: " << savingAccountBalance << endl;
    return;
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

void activities(){
    takeInputFromTheBalanceInformationSheet();

    int repeatOperation = false;
    while(true){
        // ask the user if he/she wants to repeat the operation
        if(repeatOperation==true && repeatationChecker()==false){
            break;
        }

        repeatOperation = true;

        cout << "What do you want to do?" << endl;
        cout << "\t1. Add your balance" << endl;
        cout << "\t2. Transfer balance" << endl;

        cout << "Your response: ";
        int operationType;
        cin >> operationType;

        if(operationType == 1) addBalance();
        else if(operationType == 2) transferBalance();
    }

    updateTheBalanceInformationSheet();
}
