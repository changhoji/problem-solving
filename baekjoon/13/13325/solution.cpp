#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int cost[2100000];
int dp[2100000];

int answer = 0;

void TreeDP(int root, int depth, int k){
    if(depth == k){
        dp[root] = 0;
        return;
    }

    int left = root*2;
    int right = root*2 + 1;

    TreeDP(left, depth+1, k);
    TreeDP(right, depth+1, k);

    dp[root] = max(cost[left] + dp[left], cost[right] + dp[right]);

    answer += abs(dp[left]+cost[left] - dp[right]-cost[right]);
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int k;
    cin >> k;

    int n = 2 * ((1 << k) - 1) + 1;

    for(int i = 2; i < n+1; i++){
        cin >> cost[i];
        answer += cost[i];
    }

    TreeDP(1, 0, k);

    cout << answer << '\n';

    return 0;
}
