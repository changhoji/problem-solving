#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

typedef pair<int, int> pll;

pll Dijkstra(int N, int from, int v1, int v2, vector<vector<pll>> &adj){
    vector<int> dist(N+1, INF);
    dist[from] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, from));

    while(!pq.empty()){
        pll cur = pq.top();
        pq.pop();

        int d = cur.first;
        int now = cur.second;

        for(auto p: adj[now]){
            int next = p.first;
            int cost = p.second;

            if(d + cost < dist[next]){
                dist[next] = d + cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    return make_pair(dist[v1], dist[v2]);
}

int main(){
    int N, E;
    cin >> N >> E;

    vector<vector<pll>> adj(N+1);

    int a, b, c;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    int v1, v2;
    cin >> v1 >> v2;

    pll temp1 = Dijkstra(N, 1, v1, v2, adj), temp2 = Dijkstra(N, N, v1, v2, adj);
    int connect = Dijkstra(N, v1, v1, v2, adj).second;

    int start[2] = { temp1.first, temp1.second }; // 1 <-> v1, 1 <-> v2
    int end[2] = { temp2.first, temp2.second };   // N <-> v1, N <-> v2

    int answer = INF;

    if(connect != INF){
        answer = min(answer, start[0] + end[1]);
        answer = min(answer, start[1] + end[0]);
        answer += connect;
    }

    if(answer >= INF) cout << "-1\n";
    else cout << answer << '\n';

    return 0;
}
