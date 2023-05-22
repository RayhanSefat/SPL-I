#include<bits/stdc++.h>
#include "Data Analysis.h";

float portionTaxCalculate(float annualIncome, float rangeStart, float rangeEnd, float fractionOfTax){
    if(annualIncome < rangeStart)
        return 0.0;

    float considerableAmount = min(annualIncome, rangeEnd) - rangeStart;

    float taxAmount;
    taxAmount = considerableAmount * fractionOfTax;

    return taxAmount;
}

float getTotalAnnualTaxAmmount(float annualIncome){
    float totalTaxAmount = 0.0;

    totalTaxAmount += portionTaxCalculate(annualIncome, 0.0, 3e5, 0.0);
    totalTaxAmount += portionTaxCalculate(annualIncome, 3e5, 4e5, 0.05);
    totalTaxAmount += portionTaxCalculate(annualIncome, 4e5, 7e5, 0.10);
    totalTaxAmount += portionTaxCalculate(annualIncome, 7e5, 11e5, 0.15);
    totalTaxAmount += portionTaxCalculate(annualIncome, 11e5, 16e5, 0.20);

    if(annualIncome > 16e5){
        totalTaxAmount += (annualIncome - 16e5) * 0.25;
    }

    return totalTaxAmount;
}

void calculateTax(){
    float annualIncome = 0.0;
    for(int i=0; i<12; i++){
        annualIncome += monthwiseEarning[i];
    }

    cout << "Your income this year: " << annualIncome << endl;
    cout << "Amount of tax: " << getTotalAnnualTaxAmmount(annualIncome) << endl;
    cout << endl;

    return;
}

