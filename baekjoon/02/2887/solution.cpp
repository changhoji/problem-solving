#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int par[100000];

int Find(int n){
    if(par[n] == n) return n;
    else return par[n] = Find(par[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a != b){
        par[a] = b;
    }
}

struct Planet{
    int idx;
    int x;
    int y;
    int z;
};

struct Edge{
    int u;
    int v;
    int cost;

    Edge(int u, int v, int cost): u(u), v(v), cost(cost) {}
};

struct Compare{
    bool operator()(const Edge &a, const Edge &b){
        return a.cost > b.cost;
    }
};

bool CompX(const Planet &a, const Planet &b){
    return a.x < b.x;
}
bool CompY(const Planet &a, const Planet &b){
    return a.y < b.y;
}
bool CompZ(const Planet &a, const Planet &b){
    return a.z < b.z;
}

int Kruskal(vector<Planet> &planet){
    int N = planet.size();
    priority_queue<Edge, vector<Edge>, Compare> pq;

    int front, back;

    sort(planet.begin(), planet.end(), CompX);

    pq.push(Edge(planet[0].idx, planet[1].idx, abs(planet[0].x-planet[1].x)));
    pq.push(Edge(planet[N-2].idx, planet[N-1].idx, abs(planet[N-2].x-planet[N-1].x)));

    for(int i = 1; i < N-2; i++){
        front = abs(planet[i].x-planet[i-1].x);
        back = abs(planet[i].x-planet[i+1].x);

        pq.push(Edge(planet[i].idx, planet[i-1].idx, front));
        pq.push(Edge(planet[i].idx, planet[i+1].idx, back));
    }

    sort(planet.begin(), planet.end(), CompY);

    pq.push(Edge(planet[0].idx, planet[1].idx, abs(planet[0].y-planet[1].y)));
    pq.push(Edge(planet[N-2].idx, planet[N-1].idx, abs(planet[N-2].y-planet[N-1].y)));

    for(int i = 1; i < N-2; i++){
        front = abs(planet[i].y-planet[i-1].y);
        back = abs(planet[i].y-planet[i+1].y);

        pq.push(Edge(planet[i].idx, planet[i-1].idx, front));
        pq.push(Edge(planet[i].idx, planet[i+1].idx, back));
    }

    sort(planet.begin(), planet.end(), CompZ);

    pq.push(Edge(planet[0].idx, planet[1].idx, abs(planet[0].z-planet[1].z)));
    pq.push(Edge(planet[N-2].idx, planet[N-1].idx, abs(planet[N-2].z-planet[N-1].z)));

    for(int i = 1; i < N-2; i++){
        front = abs(planet[i].z-planet[i-1].z);
        back = abs(planet[i].z-planet[i+1].z);

        
        pq.push(Edge(planet[i].idx, planet[i-1].idx, front));
        pq.push(Edge(planet[i].idx, planet[i+1].idx, back));
    }

    int result = 0;
    N--;
    while(N){
        auto cur = pq.top();
        pq.pop();

        if(Find(cur.u) == Find(cur.v)) continue;

        result += cur.cost;
        Union(cur.u, cur.v);
        N--;
    }

    return result;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N, x, y, z;
    cin >> N;
    
    vector<Planet> planet(N);
    for(int i = 0; i < N; i++){
        par[i] = i;
        planet[i].idx = i;
        cin >> planet[i].x >> planet[i].y >> planet[i].z;
    }

    int answer = 0;

    if(N == 2){
        answer = min(min(abs(planet[0].x-planet[1].x), abs(planet[0].y-planet[1].y)), abs(planet[0].z-planet[1].z));
    } else if(N >= 3){
        answer = Kruskal(planet);
    }
    
    cout << answer << '\n';

    return 0;
}
