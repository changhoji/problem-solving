#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, cnt, n;
    cin >> N;

    n = 665;
    cnt = 0;

    while(cnt < N){
        n++;

        int cntSix = 0;
        bool isDoom = false;
        for(char c: to_string(n)){
            if(c == '6') cntSix++;
            else cntSix = 0;

            if(cntSix >= 3){
                isDoom = true;
                break;
            }
        }

        if(isDoom) cnt++;
    }

    cout << n << '\n';

    return 0;
}
