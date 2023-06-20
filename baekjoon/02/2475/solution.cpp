#include <iostream>
using namespace std;

int main(){
    int num, result = 0;

    for(int i = 0; i < 5; i++){
        cin >> num;
        result += num*num;
    }
    
    result %= 10;

    cout << result << '\n';

    return 0;
}
