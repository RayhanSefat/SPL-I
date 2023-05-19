#include<bits/stdc++.h>
#include "Monthwise.h";

int getStartMonth(){
    cout << "Enter the starting month." << endl;

    int monthNumber = getMonthNumber();

    return monthNumber;
}

int getEndMonth(){
    cout << "Enter the ending month." << endl;

    int monthNumber = getMonthNumber();

    return monthNumber;
}

const int N = 12;
float x[N], y[N];

void setVariableValues(){
    for(int i=0; i<N; i++){
        x[i] = monthwiseEarning[i];
        y[i] = monthwiseEarning[i] - (monthwiseNeedSpending[i] + monthwiseDemandSpending[i]);
    }

    return;
}

float sumCalculate(int xPow, int yPow, int startingMonth, int endingMonth){
    float sum = 0.0;

    for(int i=startingMonth - 1; i<endingMonth; i++){
        float currentValue = 1.0;

        for(int j=0; j<xPow; j++){
            currentValue *= x[i];
        }

        for(int j=0; j<yPow; j++){
            currentValue *= y[i];
        }

        sum += currentValue;
    }

    return sum;
}

int const degreeOfEqn = 5;
double A[degreeOfEqn][degreeOfEqn], B[degreeOfEqn][1];

void buildMatrixSystem(int startingMonth, int endingMonth){
    for(int i=0; i<degreeOfEqn; i++){
        for(int j=0; j<degreeOfEqn; j++){
            if(!i && !j){
                A[i][j] = N;
                continue;
            }

            A[i][j] = sumCalculate(i+j, 0, startingMonth, endingMonth);
        }
    }

    for(int i=0; i<degreeOfEqn; i++){
        B[i][0] = sumCalculate(i, 1, startingMonth, endingMonth);
    }

    return;
}

void substractRow(int row1, int row2){
    double value1 = A[row1][row2];
    double value2 = A[row2][row2];

    for(int i=0; i<degreeOfEqn; i++){
        A[row1][i] = value2 * A[row1][i] - value1 * A[row2][i];
    }

    B[row1][0] = value2 * B[row1][0] - value1 * A[row2][0];

    return;
}

void diagojnaliseMatrixSystem(){
    for(int i=0; i<degreeOfEqn; i++){
        for(int j=0; j<degreeOfEqn; j++){
            if(i == j){
                continue;
            }

            substractRow(j, i);
        }
    }

    for(int i=0; i<degreeOfEqn; i++){
        if(A[i][i] != 0)
            B[i][0] /= A[i][i];
    }

    return;
}

void printFinalEquation(){
    cout << "The final equation of the regression modeling is:" << endl;
    cout << "\t\ty = ";

    for(int i=0; i<degreeOfEqn; i++){
        if(i != 0)
            cout << "+ ";

        cout << B[i][0];

        if(i)
            cout << "x^" << i << " ";
    }

    cout << endl;

    return;
}

void buildRegressionMoidel(){
    setVariableValues();

    int staringMonth = getStartMonth();
    int endingMonth = getEndMonth();
    buildMatrixSystem(staringMonth, endingMonth);

    diagojnaliseMatrixSystem();

    printFinalEquation();

    return;
}
