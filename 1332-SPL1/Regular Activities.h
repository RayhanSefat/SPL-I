#include<bits/stdc++.h>
#include "Monthwise.h";

using namespace std;

bool repeatationChecker()
{
    cout << "Do you want to conduct one more operation?" << endl;
    cout << "\t1. Yes" << endl;
    cout << "\t2. No" << endl;
    cout << "Your response: ";

    int repeatingCommand;
    cin >> repeatingCommand;

    if(repeatingCommand == 1) return true;
    return false;
}

void printTerminatinatingMessage(){
    system("cls");

    cout << "Your data has been updated. Thank you. " << endl;

    return;
}

int getMonthNumber(){
    cout << "\nEnter month: " << endl;
    for(int i=0; i<12; i++){
        cout << i+1 << ". " << monthName[i] << endl;
    }

    cout << endl;

    cout << "Your response: ";
    int monthNumber;
    cin >> monthNumber;
    return monthNumber;
}

void activities(){
    setMonthName();

    takeInputFromTheBalanceInformationSheet();
    readSpendings();
    readMonthwiseAccounts();

    int monthNumber = getMonthNumber();

    int repeatOperation = false;
    while(true){
        // ask the user if he/she wants to repeat the operation
        if(repeatOperation==true && repeatationChecker()==false){
            printTerminatinatingMessage();
            break;
        }

        if(repeatOperation == true){
            system("cls");
        }

        repeatOperation = true;

        cout << "What do you want to do?" << endl;
        cout << "\t1. Add your balance" << endl;
        cout << "\t2. Transfer balance" << endl;
        cout << "\t3. Spend Money" << endl;
        cout << "\t4. Show monthwise activity" << endl;

        cout << "Your response: ";
        int operationType;
        cin >> operationType;

        if(operationType == 1) addBalance();
        else if(operationType == 2) transferBalance();
        else if(operationType == 3) spendMoney();
        else if(operationType == 4) printMonthwiseDetails();

        updateTheBalanceInformationSheet();
        updateSpendings();
        updateMonthwiseAccounts(monthNumber);
    }
}
