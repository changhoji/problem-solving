#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int w[1001];
vector<int> adj[1001];
stack<int> special;

pii TreeDP(int root, int parent){
    pii result;

    result.first = w[root];
    if(special.empty())
        result.first -= special.top();
    result.second = w[root];

    pii a, b;
    for(auto child: adj[root]){
        if(child == parent) continue;

        a = TreeDP(child, root);
        special.push(w[root]);
        b = TreeDP(child, root);
        special.pop();

        result.first += min(a.first, a.second);
        result.second += min(b.first, b.second);
    }

    return result;
}

int main(){
    int n, root;
    cin >> n >> root;

    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }

    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pii result = TreeDP(1, 0);

    cout << min(result.first, result.second) << '\n';

    return 0;
}
