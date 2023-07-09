#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(int N, int V, vector<vector<int>> &adj, vector<bool> &visited){
    visited[V] = true;

    cout << V << ' ';

    for(int next: adj[V])
        if(visited[next] == false)
            DFS(N, next, adj, visited);
}

void BFS(int N, int V, vector<vector<int>> &adj){
    vector<bool> visited(N+1, false);
    visited[V] = true;

    queue<int> q;
    q.push(V);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for(int next: adj[cur]){
            if(visited[next] == false){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> adj(N+1);

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(N+1, false);

    DFS(N, V, adj, visited);
    cout << '\n';

    BFS(N, V, adj);
    cout << '\n';
}
