#include <iostream>
using namespace std;

bool IsPrimeNumber(int n){
    if(n == 1) return false;
    for(int div = 2; div <= n/2; div++){
        if(n % div == 0) return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    
    int answer = 0;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        
        if(IsPrimeNumber(num)) answer++;
    }

    cout << answer << '\n';

    return 0;
}
