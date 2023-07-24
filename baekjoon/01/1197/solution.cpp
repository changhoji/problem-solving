#include <iostream>
#include <queue>
using namespace std;

struct Edge {
    int u;
    int v;
    int cost;

    Edge(int u, int v, int cost): u(u), v(v), cost(cost) {}
};

struct Comp {
    bool operator()(const Edge &a, const Edge& b){
        return a.cost > b.cost;
    }
};

int par[10001];

int Find(int n){
    if(par[n] == n) return n;
    else return par[n] = Find(par[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a != b) par[a] = b;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    for(int i = 1; i <= V; i++){
        par[i] = i;
    }

    priority_queue<Edge, vector<Edge>, Comp> pq;

    int A, B, C;
    for(int i = 0; i < E; i++){
        cin >> A >> B >> C;
        pq.push(Edge(A, B, C));
    }

    int answer = 0;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        if(Find(cur.u) == Find(cur.v)) continue;

        answer += cur.cost;
        Union(cur.u, cur.v);
    }

    cout << answer << '\n';
}
