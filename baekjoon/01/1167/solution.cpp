#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[100001];

pii FarthestVertex(int V, int start){
    vector<int> dist(V+1, -1);

    dist[start] = 0;
    pii result = {start, 0};

    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int now = s.top();
        s.pop();

        for(auto p: adj[now]){
            int next = p.first;
            int cost = p.second;

            if(dist[next] == -1){
                dist[next] = dist[now] + cost;
                s.push(next);
                if(dist[next] > result.second){
                    result = make_pair(next, dist[next]);
                }
            }
        }
    }

    return result;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int V;
    cin >> V;

    int n, u, c;
    for(int i = 0; i < V; ++i){
        cin >> n;
        while(true){
            cin >> u;
            if(u == -1) break;
            cin >> c;
            adj[n].push_back(make_pair(u, c));
        }
    }

    auto result = FarthestVertex(V, 2);

    int answer = FarthestVertex(V, result.first).second;

    cout << answer << '\n';

    return 0;
}
