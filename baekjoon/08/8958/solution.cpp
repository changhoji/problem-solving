#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++){
        string str;
        cin >> str;

        int before = 0;
        int score = 0;

        for(char c: str){
            if(c == 'O'){
                score += before+1;
                before++;
            } else{
                before = 0;
            }
        }

        cout << score << '\n';
    }

    return 0;
}
