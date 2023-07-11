#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int KevinBaconNumber(int N, int start, vector<vector<int>> &adj){
    int result = 0;

    vector<int> distance(N+1, -1);
    distance[start] = 0;

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next: adj[cur]){
            if(distance[next] != -1) continue;

            distance[next] = distance[cur] + 1;
            result += distance[next];
            q.push(next);
        }
    }

    return result;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);

    int A, B;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int minNumber = 100000;
    int answer = -1;
    for(int i = 1; i <= N; i++){
        int now = KevinBaconNumber(N, i, adj);
        if(minNumber > now){
            minNumber = now;
            answer = i;
        }
    }

    cout << answer << '\n';

    return 0;
}
