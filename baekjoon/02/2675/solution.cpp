#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++){
        int R;
        string S, P;

        cin >> R >> S;

        for(char c: S){
            P.append(R, c);
        }

        cout << P << '\n';
    }

    return 0;
}
