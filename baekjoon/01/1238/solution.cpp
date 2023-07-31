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
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pll>> adj(N+1);
    vector<vector<int>> distance(N+1, vector<int>(N+1, INF));

    for(int i = 1; i <= N; i++){
        distance[i][i] = 0;
    }

    int u, v, w;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    for(int i = 1; i <= N; i++){
        Dijkstra(i, adj, distance[i]);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++){
        int now = distance[i][X] + distance[X][i];
        answer = (answer > now) ? answer : now;
    }

    cout << answer << '\n';

    return 0;
}
