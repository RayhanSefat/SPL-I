#include <bits/stdc++.h>

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



float needSpending;
float demandSpending;
float savedAmount;

void readSpendings(){
    fptr3.open("Spendings.txt");

    fptr3 >> needSpending;
    fptr3 >> demandSpending;
    fptr3 >> savedAmount;

    fptr3.close();

    return;
}


void updateSpendings(){
    fptr3.open("Spendings.txt");

    fptr3 << needSpending << endl;
    fptr3 << demandSpending << endl;
    fptr3 << savedAmount << endl;

    fptr3.close();

    return;
}



float monthwiseEarning[12];
float monthwiseNeedSpending[12];
float monthwiseDemandSpending[12];


float tempEarnig = 0;
float tempNeedSpending = 0;
float tempDemandSpending = 0;

void readMonthwiseAccounts(){
    fptr3.open("Monthwise Accounts.txt");

    for(int i=0; i<12; i++){
        fptr3 >> monthwiseEarning[i];
        fptr3 >> monthwiseNeedSpending[i];
        fptr3 >> monthwiseDemandSpending[i];
    }

    fptr3.close();
}

void updateMonthwiseAccounts(int monthNumber){
    fptr3.open("Monthwise Accounts.txt");

    monthwiseEarning[monthNumber - 1] += tempEarnig;
    monthwiseNeedSpending[monthNumber - 1] += tempNeedSpending;
    monthwiseDemandSpending[monthNumber - 1] += tempDemandSpending;

    tempEarnig = 0.0;
    tempNeedSpending = 0.0;
    tempDemandSpending = 0.0;

    for(int i=0; i<12; i++){
        fptr3 << monthwiseEarning[i] << endl;
        fptr3 << monthwiseNeedSpending[i] << endl;
        fptr3 << monthwiseDemandSpending[i] << endl;
    }

    fptr3.close();
}
