#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<string> names(N+1);
    map<string, int> number;

    string name;
    for(int i = 1; i <= N; i++){
        cin >> name;
        names[i] = name;
        number[name] = i;
    }

    string problem;
    for(int i = 0; i < M; i++){
        cin >> problem;
        if(isdigit(problem[0])){
            cout << names[stoi(problem)] << '\n';
        }
        else{
            cout << number[problem] << '\n';
        }
    }

    return 0;
}
