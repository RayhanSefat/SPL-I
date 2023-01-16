#include <bits/stdc++.h>

using namespace std;

fstream fptr1;

string actualPassword;

void signUp(){
    fptr1 << "Yes" << endl;

    cout << "WELCOME! You have to register first!" << endl;

    cout << "Enter your first name: ";
    string firstName;
    cin >> firstName;
    fptr1 << firstName << endl;

    cout << "Enter your last name: ";
    string lastName;
    cin >> lastName;
    fptr1 << lastName << endl;

    string password;
    int minimumLenthOfPassword = 8;
    do{
        cout << "Enter your password(at least 8 characters): ";
        cin >> password;

        if(password.size() >= minimumLenthOfPassword){
            fptr1 << password << endl;
            break;
        }

        cout << "Password is too short. Please try again." << endl;
    }while(true);
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

    // reading the actual password for the first time only and to keep it stored it has been declared globally
    if(fptr1.good()){
        getline(fptr1, actualPassword);
    }
    string givenPassword;
    cin >> givenPassword;

    return actualPassword == givenPassword;
}

bool initialEntrance(){
    fptr1.open("Basic Information.txt");

    string registrationStatus;
    getline(fptr1, registrationStatus);

    if(registrationStatus == "No"){
        fptr1.seekp(0);

        signUp();

        cout << "Congratulations! You have been registered successfully!" << endl;

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
