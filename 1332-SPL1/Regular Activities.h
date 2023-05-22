#include<bits/stdc++.h>
#include "Taxation.h";

using namespace std;

bool repeatationChecker()
{
    cout << "Do you want to conduct one more operation?" << endl;
    cout << "\t1. Yes" << endl;
    cout << "\t2. No" << endl;
    cout << "Your response: ";

    int repeatingCommand;
    cin >> repeatingCommand;

    if(repeatingCommand == 1)
        return true;
    return false;
}

void printTerminatinatingMessage(){
    system("cls");

    cout << "Your data has been updated. Thank you. " << endl;

    return;
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
        cout << "\t4. Show monthwised activity analysis" << endl;
        cout << "\t5. Show summary data" << endl;
        cout << "\t6. Show regression analysis" << endl;
        cout << "\t7. Calculate tax amount of the year" << endl;

        cout << "Your response: ";
        int operationType;
        cin >> operationType;

        if(operationType == 1) addBalance();
        else if(operationType == 2) transferBalance();
        else if(operationType == 3) spendMoney();
        else if(operationType == 4) printMonthwiseDetails();
        else if(operationType == 5) printFinanceSummary();
        else if(operationType == 6) buildRegressionMoidel();
        else if(operationType == 7) calculateTax();

        updateTheBalanceInformationSheet();
        updateSpendings();
        updateMonthwiseAccounts(monthNumber);
    }
}
