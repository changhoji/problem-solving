#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll X;
    cin >> X;

    int N;
    cin >> N;

    ll a, b;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        sum += a*b;
    }

    cout << ((X == sum) ? "Yes\n" : "No\n");

    return 0;
}
