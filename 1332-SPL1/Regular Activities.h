#include<bits/stdc++.h>
#include "Spending Activities.h";

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
    cout << "Enter month: " << endl;
    cout << "\t1. January" << endl;
    cout << "\t2. February" << endl;
    cout << "\t3. March" << endl;
    cout << "\t4. April" << endl;
    cout << "\t5. May" << endl;
    cout << "\t6. June" << endl;
    cout << "\t7. July" << endl;
    cout << "\t8. August" << endl;
    cout << "\t9. September" << endl;
    cout << "\t10. Octobet" << endl;
    cout << "\t11. November" << endl;
    cout << "\t12. December" << endl;

    cout << "Your response: ";
    int monthNumber;
    cin >> monthNumber;
    return monthNumber;
}

void activities(){
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

        cout << "Your response: ";
        int operationType;
        cin >> operationType;

        if(operationType == 1) addBalance();
        else if(operationType == 2) transferBalance();
        else if(operationType == 3) spendMoney();
    }

    updateTheBalanceInformationSheet();
    updateSpendings();
    updateMonthwiseAccounts(monthNumber);
}
