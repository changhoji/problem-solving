#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;

    int cost[501];
    int num;
    
    vector<int> out[501];
    int in[501] = { 0,};

    for(int i = 1; i <= N; i++){
        cin >> cost[i];

        cin >> num;
        while(num != -1){
            out[num].push_back(i);
            ++in[i];
            cin >> num;
        }
    }

    queue<int> q;
    int time[501] = { 0,};
    for(int i = 1; i <= N; i++){
        time[i] = cost[i];
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i: out[cur]){
            time[i] = max(time[i], time[cur] + cost[i]);
            if(--in[i] == 0){
                q.push(i);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << time[i] << '\n';
    }

    return 0;
}
