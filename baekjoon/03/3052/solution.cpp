#include <iostream>
using namespace std;

int main(){
    bool remainder[42] = { false,};
    int num, cnt = 0;

    for(int i = 0; i < 10; i++){
        cin >> num;
        int temp = num % 42;

        if(!remainder[temp]){
            remainder[temp] = true;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
