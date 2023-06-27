#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        string str;
        cin >> str;
        
        int count = 0;
        for(char c: str){
            if(c == '(')
                count++;
            else{
                count--;
                if(count < 0) break;
            }
        }
        
        if(count != 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
