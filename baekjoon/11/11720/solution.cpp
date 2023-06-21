#include <iostream>
using namespace std;

int main(){
    int N, sum = 0;
    char c;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> c;
        sum += c - '0';
    }

    cout << sum << '\n';
    
    return 0;
}
