#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N;
    cin >> N;

    deque<int> dq;

    for(int i = 0; i < N; i++){
        string cmd;
        int X;

        cin >> cmd;

        if(cmd == "push_front"){
            cin >> X;
            dq.push_front(X);
        }
        else if(cmd == "push_back"){
            cin >> X;
            dq.push_back(X);
        }
        else if(cmd == "pop_front"){
            if(dq.empty()) cout << "-1\n";
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(dq.empty()) cout << "-1\n";
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd == "size"){
            cout << dq.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << dq.empty() << '\n';
        }
        else if(cmd == "front"){
            if(dq.empty()) cout << "-1\n";
            else cout << dq.front() << '\n';
        }
        else{
            if(dq.empty()) cout << "-1\n";
            else cout << dq.back() << '\n';
        }
    }

    return 0;
}
