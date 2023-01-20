#include <bits/stdc++.h>
#include "Register and Login.h";
#include "Regular Activities.h";

using namespace std;

void fileController(){
    cout << "\t\t\t\tSoftware Project Lab 1\n";
    cout << "\t\t\tPERSONAL FINANCE MANAGEMENT PROJECT\n";
    cout << "\tA system that manages the finanacial activities of an individual\n\n\n";

    if(!initialEntrance()){
        cout << "Sorry! Login failed..." << endl;
        return;
    }

    activities();

    return;
}
