#include <bits/stdc++.h>
#include "Hashing.h"

using namespace std;

fstream fptr1;
fstream fptr2;
fstream fptr4;

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

void signUp(){
    fptr4.open("Basic Information.txt");
    fptr4 << "Yes" << endl;

    cout << "WELCOME! You have to register first!" << endl;

    cout << "Enter your first name: ";
    string firstName;
    cin >> firstName;
    fptr4 << firstName << endl;

    cout << "Enter your last name: ";
    string lastName;
    cin >> lastName;
    fptr4 << lastName << endl;

    string password;
    int minimumLenthOfPassword = 8;
    do{
        cout << "Enter your password(at least 8 characters): ";
        cin >> password;

        if(password.size() >= minimumLenthOfPassword){
            pair<long long int, long long int> hashedValuesOfPassword = hashPassword(password);

            fptr4 << hashedValuesOfPassword.first << endl;
            fptr4 << hashedValuesOfPassword.second << endl;

            break;
        }

        cout << "Password is too short. Please try again." << endl;
    }while(true);

    fptr4.close();
}

bool login(){
    cout << "Verify that you are ";

    string firstName;
    getline(fptr1, firstName);
    cout << firstName << " ";

    string lastName;
    getline(fptr1, lastName);
    cout << lastName << endl;

    cout << "Please enter the password: ";

    string givenPassword;
    cin >> givenPassword;

    long long int hashValueOfActualPassword1;
    long long int hashValueOfActualPassword2;

    if(fptr1.good()){
        fptr1 >> hashValueOfActualPassword1;
        fptr1 >> hashValueOfActualPassword2;
    }

    pair<long long int, long long int> hashedPairOfGivenPassword = {hashValueOfActualPassword1, hashValueOfActualPassword2};
    pair<long long int, long long int> hashedPairOfActualPassword = hashPassword(givenPassword);

    return hashedPairOfGivenPassword.first == hashedPairOfActualPassword.first && hashedPairOfGivenPassword.second == hashedPairOfActualPassword.second;
}

bool initialEntrance(){
    fptr1.open("Basic Information.txt");

    string registrationStatus;
    getline(fptr1, registrationStatus);

    if(registrationStatus == "No"){
        fptr1.seekp(0);

        signUp();

        cout << "Congratulations! You have been registered successfully!" << endl << endl;


        takeFinalcialInformation();

        return true;
    }

    int tryChances = 3;
    for(int i=1; i<=tryChances; i++){

        if(login()){
            cout << "Congratulations! You have been logged in successfully..." << endl;
            return true;
        }

        cout << "Wrong password!";

        if(i < tryChances){
            cout << " Please try again.";
        }

        cout << endl;
    }

    cout << "You have lost all opportunities to enter the correct password." << endl;

    fptr1.close();

    return false;
}
