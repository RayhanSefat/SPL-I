#include<bits/stdc++.h>
#include "Regression.h";

void printMaxEarning(int startingMonth, int endingMonth){
    int monthNumber = startingMonth;
    float maxEarned = monthwiseEarning[startingMonth - 1];

    for(int i = startingMonth; i<endingMonth; i++){
        if(monthwiseEarning[i] > maxEarned){
            monthNumber = i+1;
            maxEarned = monthwiseEarning[i];
        }
    }

    cout << "Maximum earning:" << endl;
    cout << "\tMonth: " << monthName[monthNumber] << endl;
    cout << "\tAmount: " << maxEarned << endl << endl;

    return;
}

void printMinEarning(int startingMonth, int endingMonth){
    int monthNumber = startingMonth;
    float minEarned = monthwiseEarning[startingMonth - 1];

    for(int i = startingMonth; i<endingMonth; i++){
        if(monthwiseEarning[i] < minEarned){
            monthNumber = i+1;
            minEarned = monthwiseEarning[i];
        }
    }

    cout << "Minimum earning:" << endl;
    cout << "\tMonth: " << monthName[monthNumber] << endl;
    cout << "\tAmount: " << minEarned << endl << endl;

    return;
}

void printMaxSavings(int startingMonth, int endingMonth){
    int monthNumber = startingMonth;
    float maxSaving = getMonthwiseSaving(startingMonth - 1);

    for(int i = startingMonth; i<endingMonth; i++){
        if(getMonthwiseSaving(i) > maxSaving){
            monthNumber = i+1;
            maxSaving = getMonthwiseSaving(i);
        }
    }

    cout << "Maximum saving:" << endl;
    cout << "\tMonth: " << monthName[monthNumber] << endl;
    cout << "\tAmount: " << maxSaving << endl << endl;

    return;
}

void printMinSavings(int startingMonth, int endingMonth){
    int monthNumber = startingMonth;
    float minSaving = getMonthwiseSaving(startingMonth - 1);

    for(int i = startingMonth; i<endingMonth; i++){
        if(getMonthwiseSaving(i) < minSaving){
            monthNumber = i+1;
            minSaving = getMonthwiseSaving(i);
        }
    }

    cout << "Minimum saving:" << endl;
    cout << "\tMonth: " << monthName[monthNumber] << endl;
    cout << "\tAmount: " << minSaving << endl << endl;

    return;
}

float getSavingsPercentage(int startingMonth, int endingMonth){
    float earnedAmount = 0.0;
    float savedAmount = 0.0;

    for(int i=startingMonth-1; i<endingMonth; i++){
        earnedAmount += monthwiseEarning[i];
        savedAmount += getMonthwiseSaving(i);
    }

    return (savedAmount / earnedAmount) * 100.0;
}

void savingEvaluate(float savingPercentage){
    printf("You saved %.2f of your earnings\n", savingPercentage);

    if(savingPercentage < 0.0){
        cout << "You spent more than you earned. If you don't change your spending habits, you cannot gain any financial developement." << endl;
        cout << "Beware of little expenses; a small leak will sink a great ship." << endl;
    }

    else if(savingPercentage < 10.0){
        cout << "According to 50-30-20 rule by Elizabeth Warren, your savings are not good enough. Learn to be aware about where you spend." << endl;
        cout << "Remember, money is a terrible master but an excellent servant." << endl << endl;
    }

    else if(savingPercentage < 20.0){
        cout << "You are almost there. Just push yourself a bit more. Good luck!!" << endl;
        cout << "Keep in mind, a penny saved is a penny earned." << endl << endl;
    }

    else{
        cout << "Excellent! Just keep it up!" << endl;
        cout << "Though money can't buy happiness, it can buy anything else on the world." << endl << endl;
    }
}

void savingsAnalysis(int startingMonth, int endingMonth){
    float savingPercentage = getSavingsPercentage(startingMonth, endingMonth);

    savingEvaluate(savingPercentage);

    return;
}

void printFinanceSummary(){
    int startingMonth = getStartMonth();
    int endingMonth = getEndMonth();

    system("cls");

    cout << endl << "\t\t\tSUMMARY" << endl << endl;

    calculateRegressionCoefficients(startingMonth, endingMonth);

    printMaxEarning(startingMonth, endingMonth);
    printMinEarning(startingMonth, endingMonth);
    printMaxSavings(startingMonth, endingMonth);
    printMinSavings(startingMonth, endingMonth);

    savingsAnalysis(startingMonth, endingMonth);
}
