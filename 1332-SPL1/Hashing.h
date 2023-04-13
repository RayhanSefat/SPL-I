#include<bits/stdc++.h>
using namespace std;

long long int generateHashValue(string password, int prime, int mod){
    long long int currentValue = 1;
    long long int totalValue = 0;

    for(char x : password){
        currentValue = (currentValue * prime) % mod;
        totalValue = totalValue + (currentValue * x) % mod;
        totalValue = totalValue % mod;
    }

    return totalValue;
}

pair<long long int, long long int> hashPassword(string password){
    int prime1 = 151;
    int prime2 = 163;

    long long int mod1 = 1e9 + 7;
    long long int mod2 = 1e9 + 9;

    long long int hashValue1 = generateHashValue(password, prime1, mod1);
    long long int hashValue2 = generateHashValue(password, prime2, mod2);

    return make_pair(hashValue1, hashValue2);
}
