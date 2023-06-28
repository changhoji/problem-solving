#include <iostream>
using namespace std;

typedef long long ll;

const int r = 31;
const int M = 1234567891;

int HashFunction(string key){
    ll sum = 0;

    ll mul = 1;

    for(int i = 0; i < key.length(); i++){
        if(i != 0) mul = (mul * r) % M;
        sum = (sum + (key[i]-'a'+1) * mul) % M;
    }

    return sum;
}

int main(){
    int L;
    string key;

    cin >> L >> key;

    cout << HashFunction(key) << '\n';

    return 0;
}
