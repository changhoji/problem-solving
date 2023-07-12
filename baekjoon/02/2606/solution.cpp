#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void DFS(int start, vector<vector<int>> &adj, vector<bool> &visited){
    answer++;

    for(int next: adj[start]){
        if(visited[next]) continue;
        visited[next] = true;
        DFS(next, adj, visited);
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(N+1, false);

    visited[1] = true;
    DFS(1, adj, visited);
    answer--;

    cout << answer << '\n';

    return 0;
}
