#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define x first
#define y second

int par[101];

int Find(int n){
    if(par[n] == n) return n;
    return par[n] = Find(par[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) par[a] = b;
}

typedef pair<double, double>  Point;

struct Edge {
    int u;
    int v;
    double cost;

    Edge(int u, int v, double c): u(u), v(v), cost(c) {}
};

struct Compare {
    bool operator()(const Edge &a, const Edge &b){
        return a.cost > b.cost;
    }
};

double Distance(const Point &a, const Point &b){
    double dx = b.x-a.x;
    double dy = b.y-a.y;

    return sqrt(dx*dx+dy*dy);
}

int main(){
    int n;
    cin >> n;

    priority_queue<Edge, vector<Edge>, Compare> pq;

    Point star[101];
    for(int i = 1; i <= n; i++){
        par[i] = i;
        cin >> star[i].x >> star[i].y;
        for(int j = 1; j < i; j++){
            pq.push(Edge(j, i, Distance(star[i], star[j])));
        }
    }

    double answer = 0;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        if(Find(cur.u) == Find(cur.v)) continue;

        Union(cur.u, cur.v);
        answer += cur.cost;
    }

    cout << answer << '\n';

    return 0;
}
