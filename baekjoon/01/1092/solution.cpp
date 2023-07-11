#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N, M;

    cin >> N;
    vector<int> crane(N);
    for(int i = 0; i < N; i++){
        cin >> crane[i];
    }
    sort(crane.begin(), crane.end(), greater<int>());

    cin >> M;
    vector<int> box(M);
    for(int i = 0; i < M; i++){
        cin >> box[i];
    }
    sort(box.begin(), box.end(), greater<int>());

    int answer = 0;
    int moved = 0;
    bool flag = false;
    while(moved < M){
        flag = false; // moved in this time
        for(int i = 0; i < crane.size(); i++){ // for each crane
            vector<int>::iterator iter;
            for(iter = box.begin(); iter < box.end(); iter++){ // for each box
                if(crane[i] >= *iter){ // can move
                    moved++;
                    flag = true;
                    box.erase(iter);
                    break;
                }
            }
            if(iter == box.end()) break; // no more possible crane
        }
        if(flag == false){
            answer = -1;
            break;
        }
        answer++;
    }

    cout << answer << '\n';

    return 0;
}
