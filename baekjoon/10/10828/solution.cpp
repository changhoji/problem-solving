#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    
    int N;
    cin >> N;

    string cmd;
    int X;

    stack<int> s;

    for(int i = 0; i < N; i++){
        cin >> cmd;

        if(cmd == "push"){
            cin >> X;
            s.push(X);
        }
        else if(cmd == "pop"){
            if(s.empty()){
                cout << "-1\n";
            }
            else{
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(cmd == "size"){
            cout << s.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << s.empty() << '\n';
        }
        else{
            if(s.empty()){
                cout << "-1\n";
            }
            else{
                cout << s.top() << '\n';
            }
        }
    }

    return 0;
}
