#include <iostream>
#include <queue>
using namespace std;

int par[100001];

int Find(int n){
    if(par[n] == n) return n;
    else return par[n] = Find(par[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a != b) par[a] = b;
}

struct Edge {
    int u;
    int v;
    int cost;

    Edge(int u, int v, int c): u(u), v(v), cost(c) {}
};

struct Compare {
    bool operator()(const Edge &a, const Edge &b){
        return a.cost > b.cost;
    }
};

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        par[i] = i;
    }

    priority_queue<Edge, vector<Edge>, Compare> pq;
    int A, B, C;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;
        pq.push(Edge(A, B, C));
    }

    int mst = 0;
    int maxCost = 0;
    N--;
    while(N){
        auto cur = pq.top();
        pq.pop();

        if(Find(cur.u) == Find(cur.v)) continue;
        
        N--;
        Union(cur.u, cur.v);
        mst += cur.cost;
        maxCost = max(maxCost, cur.cost);
    }

    cout << mst - maxCost << '\n';

    return 0;
}
