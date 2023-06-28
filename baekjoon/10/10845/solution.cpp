#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N;
    cin >> N;

    queue<int> q;

    for(int i = 0; i < N; i++){
        string cmd;
        int X;

        cin >> cmd;

        if(cmd == "push"){
            cin >> X;
            q.push(X);
        }
        else if(cmd == "pop"){
            if(q.empty()) cout << "-1\n";
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(cmd == "size"){
            cout << q.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << q.empty() << '\n';
        }
        else if(cmd == "front"){
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        }
        else{
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }
    }

    return 0;
}
