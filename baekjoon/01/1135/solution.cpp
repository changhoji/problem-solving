#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NMAX 50

int dp[NMAX]; // dp[i]: needed max time when starts from i
vector<int> adj[NMAX];

void TreeDP(int root){
    dp[root] = 0;
    if(adj[root].empty()) return;

    vector<int> times;
    for(auto child: adj[root]){
        TreeDP(child);
        times.push_back(dp[child]+1);
    }

    sort(times.begin(), times.end(), greater<int>());

    int result = 0;
    for(int i = 0; i < times.size(); i++){
        result = max(result, times[i] + i);
    }

    dp[root] = result;
}

int main(){
    int N;
    cin >> N;

    int par;
    cin >> par;
    for(int i = 1; i < N; i++){
        cin >> par;
        adj[par].push_back(i);
    }

    TreeDP(0);

    cout << dp[0] << '\n';

    return 0;
}
