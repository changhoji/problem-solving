#include <iostream>
using namespace std;

int main(){
    int N, X, num;
    cin >> N >> X;

    for(int i = 0; i < N; i++){
        cin >> num;
        if(num < X) cout << num << " ";
    }
    cout << '\n';

    return 0;
}
