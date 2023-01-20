#include <bits/stdc++.h>

using namespace std;

fstream fptr2;

void takeFinalcialInformation(){
    fptr2.open("Balance Information.txt");

    cout << "Enter your current cash balance: ";
    float cashBalance;
    cin >> cashBalance;
    fptr2 << cashBalance << endl;

    cout << "Enter your current running account balance: ";
    float runningAccountBalance;
    cin >> runningAccountBalance;
    fptr2 << runningAccountBalance << endl;


    cout << "Enter your current saving account balance: ";
    float savingAccountBalance;
    cin >> savingAccountBalance;
    fptr2 << savingAccountBalance << endl;

    cout << "Saving account interest rate per year (in percent): ";
    float savingAccountInteresfRate;
    cin >> savingAccountInteresfRate;
    fptr2 << savingAccountInteresfRate << endl;

    cout << "Enter the number of companies you have shares of: ";
    int numberOfCompanies;
    cin >> numberOfCompanies;
    fptr2 << numberOfCompanies << endl;

    cout << "Enter the share prizes: " << endl;
    float sharePrize[numberOfCompanies + 1];
    for(int i=1; i<=numberOfCompanies; i++){
        cout << "Company " << i << " share prize: ";
        cin >> sharePrize[i];
        fptr2 << sharePrize[i] << endl;
    }

    cout << "Enter your current credit card debit(0 if you don't have any credit card): ";
    float creditCardDebit;
    cin >> creditCardDebit;
    fptr2 << creditCardDebit << endl;

    fptr2.close();

    return;
}
