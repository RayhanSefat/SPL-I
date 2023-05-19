#include <bits/stdc++.h>
#include "Spending Activities.h";

string monthName[12];

void setMonthName(){
    monthName[0] = "January";
    monthName[1] = "February";
    monthName[2] = "March";
    monthName[3] = "April";
    monthName[4] = "May";
    monthName[5] = "June";
    monthName[6] = "July";
    monthName[7] = "August";
    monthName[8] = "September";
    monthName[9] = "October";
    monthName[10] = "November";
    monthName[11] = "December";
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

void printAnnualEarningAndSaving(float totalIncomeOfTheYear, float totalSavingsOfTheYear){
    cout << "Total earning of the year: " << totalIncomeOfTheYear << endl;
    cout << "Total savings of the year: " << totalSavingsOfTheYear << endl;

    return;
}

void printMonthwiseDetails(){
    cout << "Monthwise details have been shown bellow:" << endl << endl;

    float totalIncomeOfTheYear = 0.0;
    float totalSavingsOfTheYear = 0.0;

    for(int i=0; i<12; i++){
        float savingsOfTheMonth = monthwiseEarning[i] - (monthwiseNeedSpending[i] + monthwiseDemandSpending[i]);

        cout << "Month: " << monthName[i] << endl;
        cout << "Earning: " << monthwiseEarning[i] << endl;
        cout << "Spending for need: " << monthwiseNeedSpending[i] << endl;
        cout << "Spending for demand: " << monthwiseDemandSpending[i] << endl;
        cout << "Saved: " << savingsOfTheMonth << endl;

        if(savingsOfTheMonth < 0.0){
            cout << "You spent more than you earned on month " << monthName[i] << ". Please be careful about your spending habits." << endl;
        }

        cout << endl;

        totalIncomeOfTheYear += monthwiseEarning[i];
        totalSavingsOfTheYear += savingsOfTheMonth;
    }

    printCashBalance();
    printRunningAccountBalance();
    printSavingAccountBalance();
    printSavingAccountBalance();

    printAnnualEarningAndSaving(totalIncomeOfTheYear, totalSavingsOfTheYear);

    return;
}
