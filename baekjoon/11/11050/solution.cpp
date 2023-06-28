#include <iostream>
using namespace std;

int Combination(int n, int k){
    if(k == 0 || k == n) return 1;
    return Combination(n-1, k-1) + Combination(n-1, k);
}

int main(){
    int N, K;
    cin >> N >> K;

    cout << Combination(N, K) << '\n';

    return 0;
}
