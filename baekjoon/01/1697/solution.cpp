#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int MinimumTime(int N, int K){
    int time[100001];
    fill(time, time+100001, -1);
    time[N] = 0;

    queue<int> q;
    q.push(N);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == K) return time[K];

        if(cur-1 >= 0 && time[cur-1] == -1){
            q.push(cur-1);
            time[cur-1] = time[cur] + 1;
        }
        if(cur+1 <= 100000 && time[cur+1] == -1){
            q.push(cur+1);
            time[cur+1] = time[cur] + 1;
        }
        if(cur*2 <= 100000 && time[cur*2] == -1){
            q.push(cur*2);
            time[cur*2] = time[cur] + 1;
        }
    }

    return -1;
}

int main(){
    int N, K;
    cin >> N >> K;

    cout << MinimumTime(N, K) << '\n';

    return 0;
}
