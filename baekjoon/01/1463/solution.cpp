#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001] = { 0,};

int MakeOne(int n){
    if(n == 1) return 0;
    if(arr[n] != 0) return arr[n];

    int a = 10000000;
    int b = 10000000;
    int c = 10000000;

    if((n % 3) == 0) a = MakeOne(n / 3) + 1;
    if((n % 2) == 0) b = MakeOne(n / 2) + 1;
    c = MakeOne(n - 1) + 1;

    return arr[n] = min(a, min(b, c));
}

int main(){
    int N;
    cin >> N;

    cout << MakeOne(N) << '\n';

    return 0;
}
