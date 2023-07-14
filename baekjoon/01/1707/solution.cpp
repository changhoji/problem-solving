#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool answer;

void DFS(int start, vector<vector<int>> &adj, vector<int> &color){
    for(auto next: adj[start]){
        if(color[next] == color[start]) {
            answer = false;
            return;
        }
        if(color[next] == -1){
            color[next] = (color[start] == 1) ? 0 : 1;
            DFS(next, adj, color);
        }
    }
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int K;
    cin >> K;

    int V, E, u, v;
    for(int tc = 1; tc <= K; tc++){
        cin >> V >> E;

        vector<vector<int>> adj(V+1);
        vector<int> color(V+1, -1);

        for(int i = 0; i < E; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        answer = true;
        for(int start = 1; start <= V; start++){
            if(color[start] != -1) continue;
            color[start] = 0;
            DFS(start, adj, color);
        }

        if(answer) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
