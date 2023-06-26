#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(a % b == 0) return b;
    else return GCD(b, a%b);
}

int LCM(int a, int b){
    return a * b / GCD(a, b);
}

int main(){
    int A, B;
    cin >> A >> B;

    cout << GCD(A, B) << '\n';
    cout << LCM(A, B) << '\n';

    return 0;
}
