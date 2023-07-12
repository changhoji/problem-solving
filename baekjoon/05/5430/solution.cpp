#include <iostream>
#include <deque>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(false);
    
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        deque<int> dq;

        string p, array;
        int n, num;

        cin >> p >> n >> array;

        num = 0;
        if(n){
            for(char c: array){
                if(c == '[') continue;
                if(c == ',' || c == ']'){
                    dq.push_back(num);
                    num = 0;
                }
                else{
                    num *= 10;
                    num += c - '0';
                }
            }
        }

        bool reversed = false;
        int i;
        for(i = 0; i < p.size(); i++){
            char cmd = p[i];
            if(cmd == 'R'){
                reversed = !reversed;
            }
            else{
                if(dq.empty()) break;

                if(reversed){
                    dq.pop_back();
                }
                else{
                    dq.pop_front();
                }
            }
        }

        if(i < p.size()) cout << "error\n";
        else{
            cout << '[';
            while(!dq.empty()){
                if(reversed){
                    cout << dq.back();
                    dq.pop_back();
                    if(!dq.empty()) cout << ',';

                }
                else{
                    cout << dq.front();
                    dq.pop_front();
                    if(!dq.empty()) cout << ',';
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
