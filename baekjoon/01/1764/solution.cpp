#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N, M;
    cin >> N >> M;

    set<string> s;
    vector<string> answer;

    string name;
    for(int i = 0; i < N; i++){
        cin >> name;
        s.insert(name);
    }

    for(int i = 0; i < M; i++){
        cin >> name;
        if(s.find(name) != s.end()){
            answer.push_back(name);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for(string str: answer){
        cout << str << '\n';
    }

    return 0;
}
