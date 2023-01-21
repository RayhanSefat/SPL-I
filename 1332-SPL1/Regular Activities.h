#include<bits/stdc++.h>
#include "Balance Activities.h";

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
