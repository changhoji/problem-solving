#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int dp[100001];

int TreeSize(int root, int parent){
    dp[root] = 1;
    
    for(int child: adj[root]){
        if(child == parent) continue;
        dp[root] += TreeSize(child, root);
    }

    return dp[root];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;

    int U, V;
    for(int i = 0; i < N-1; i++){
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    TreeSize(R, -1);

    for(int i = 0; i < Q; i++){
        cin >> U;
        cout << dp[U] << '\n';;
    }

    return 0;
}