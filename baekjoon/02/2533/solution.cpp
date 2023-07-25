#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001][2];
vector<int> adj[1000001];

void TreeDP(int root, int parent){
    dp[root][0] = 0;
    dp[root][1] = 1;

    for(auto child: adj[root]){
        if(child == parent) continue;
        TreeDP(child, root);
        dp[root][0] += dp[child][1];
        dp[root][1] += min(dp[child][0], dp[child][1]);
    }
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int u, v;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    TreeDP(1, -1);

    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
