#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

typedef pair<int, int> pll;

void Dijkstra(int start, vector<vector<pll>> &adj, vector<int> &dist){
    priority_queue<pll, vector<pll>, greater<pll>> pq; // first: distance, second: from
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        pll cur = pq.top();
        pq.pop();

        int d = cur.first;
        int from = cur.second;

        if(d > dist[from]) continue;

        for(pll p: adj[from]){
            int next = p.first;
            int cost = p.second;

            if(d + cost < dist[next]){
                dist[next] = d + cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<pll>> adj(N+1); // first: to, second: cost
    vector<int> dist(N+1, INF);

    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }

    int from, to;
    cin >> from >> to;

    Dijkstra(from, adj, dist);

    cout << dist[to] << '\n';

    return 0;
}
