#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

typedef long long ll;

vector<int> adj[100001];
ll dp[100001];

struct Edge {
    int u;
    int v;
};

void TreeDP(int root, int parent){
    dp[root] = 1;

    for(int child: adj[root]){
        if(child == parent) continue;
        TreeDP(child, root);
        dp[root] += dp[child];
    }
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Edge> edge;

    int u, v;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({u, v});
    }

    TreeDP(1, -1);

    ll a[100000];
    for(int i = 0; i < N-1; i++){
        cin >> a[i];
    }
    
    vector<ll> usedCount;

    for(auto e: edge){
        int temp = min(dp[e.u], dp[e.v]);

        usedCount.push_back(temp * (dp[1] - temp));
    }

    sort(usedCount.begin(), usedCount.end());
    sort(a, a+N-1, greater<ll>());
    ll answer = 0;

    for(int i = 0; i < N-1; i++){
        answer = (answer + usedCount[i]*a[i]) % MOD;
    }

    cout << answer << '\n';

    return 0;
}
