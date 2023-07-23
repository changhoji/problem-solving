#include <iostream>
using namespace std;

typedef long long ll;

ll Pow(ll A, ll B, ll C){
    if(B == 1){
        return (A % C);
    }

    ll result;
    ll half = Pow(A, B/2, C) % C;
    if(B % 2 == 1){
        result = (((half * half) % C) * A) % C;
    } else{
        result = (half * half) % C;
    }
    return result;
}

int main(){
    ll A, B, C;
    cin >> A >> B >> C;

    cout << Pow(A, B, C) << '\n';

    return 0;
}
