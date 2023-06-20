#include <iostream>
using namespace std;

int main(){
    int A, B, C, mult;
    int res[10] = { 0,};

    cin >> A >> B >> C;
    mult = A * B * C;

    for(auto c: to_string(mult)){
        res[c-'0']++;
    }

    for(auto i: res)
        cout << i << '\n';

    return 0;
}
