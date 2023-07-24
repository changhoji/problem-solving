#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int par[1001];
int depth[1001];

struct Edge {
    int u;
    int v;
    int cost;
    
    Edge(int u, int v, int cost): u(u), v(v), cost(cost) {}
};

struct Compare {
    bool operator()(const Edge &a, const Edge &b){
        return a.cost > b.cost;
    }
};

int Find(int n){
    if(par[n] == n) return n;
    else return par[n] = Find(par[n]);
}

void Union(int a, int b){
    int aa = Find(a);
    int bb = Find(b);

    if(aa == bb) return;

    if(depth[a] > depth[b]) par[bb] = aa;
    else if(depth[a] < depth[b]) par[aa] = bb;
    else{
        par[aa] = bb;
        depth[bb]++;
    }
}

typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        par[i] = i;
        depth[i] = 0;
    }

    priority_queue<Edge, vector<Edge>, Compare> pq;
    vector<pii> adj[1001];

    int A, B, C;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;

        pq.push(Edge(A, B, C));
    }

    int mst = 0;
    int connected = N-1;
    while(connected){
        auto cur = pq.top();
        pq.pop();

        if(Find(cur.u) == Find(cur.v)) continue;
        
        connected--;

        Union(cur.u, cur.v);
        mst += cur.cost;
        adj[cur.u].push_back(make_pair(cur.v, cur.cost));
        adj[cur.v].push_back(make_pair(cur.u, cur.cost));
    }

    int biggestCost[1001][1001] = { 0,};

    for(int i = 1; i <= N; i++){
        bool visited[1001] = { false,};
        visited[i] = true;

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(auto next: adj[cur]){
                if(visited[next.first]) continue; // for bfs
                visited[next.first] = true;
                q.push(next.first);

                biggestCost[i][next.first] = max(next.second, biggestCost[i][cur]);
            }
        }
    }

    int Q;
    cin >> Q;
     
    int X, Y;
    for(int i = 0; i < Q; i++){
        cin >> X >> Y;
        cout << mst - biggestCost[X][Y] << '\n';
    }

    return 0;
}
