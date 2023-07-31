#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

typedef pair<int, int> pll;

void Dijkstra(int start, vector<vector<pll>> &adj, vector<int> &distance){
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push(make_pair(0, start));

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        if(cur.first > distance[cur.second]) continue;

        for(auto edge: adj[cur.second]){
            if(distance[edge.first] > distance[cur.second] + edge.second){
                distance[edge.first] = distance[cur.second] + edge.second;
                pq.push(make_pair(distance[edge.first], edge.first));
            }
        }
    }
}

int main(){
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pll>> adj(V+1);
    vector<int> distance(V+1, INF);
    distance[K] = 0;

    int u, v, w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    Dijkstra(K, adj, distance);

    for(int i = 1; i <= V; i++){
        if(distance[i] == INF) cout << "INF\n";
        else cout << distance[i] << '\n';
    }

    return 0;
}
