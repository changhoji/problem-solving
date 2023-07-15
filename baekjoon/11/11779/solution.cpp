#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

typedef pair<int, int> pii;

void Dijkstra(int start, vector<vector<pii>> &adj, 
              vector<int> &distance, vector<vector<int>> &route){
    distance[start] = 0;
    route[start].push_back(start);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        int v = cur.second;
        int d = cur.first;

        if(distance[v] < d) continue;

        for(auto edge: adj[v]){
            int nxt = edge.first;
            int w = edge.second;

            if(distance[nxt] > distance[v] + w){
                distance[nxt] = distance[v] + w;
                route[nxt] = vector<int>(route[v]);
                route[nxt].push_back(nxt);
                pq.push(make_pair(distance[nxt], nxt));
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1);
    vector<int> distance(n+1, INF);
    vector<vector<int>> route(n+1);

    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    int from, to;
    cin >> from >> to;

    Dijkstra(from, adj, distance, route);

    cout << distance[to] << '\n';
    cout << route[to].size() << '\n';
    for(auto i: route[to]){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
