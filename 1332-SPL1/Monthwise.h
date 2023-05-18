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

void printMonthwiseDetails(){
    cout << "Monthwise details have been shown bellow:" << endl << endl;

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
    }

    return;
}
