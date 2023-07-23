#include <iostream>
#include <algorithm>
using namespace std;

enum Color {RED, GREEN, BLUE};

int main(){
    int N;
    cin >> N;

    int cost[1001][3];
    int dp[1001][3];

    cin >> cost[1][RED] >> cost[1][GREEN] >> cost[1][BLUE];
    dp[1][RED] = cost[1][RED];
    dp[1][GREEN] = cost[1][GREEN];
    dp[1][BLUE] = cost[1][BLUE];

    for(int i = 2; i <= N; i++){
        cin >> cost[i][RED] >> cost[i][GREEN] >> cost[i][BLUE];
        
        dp[i][RED] = min(dp[i-1][GREEN], dp[i-1][BLUE]) + cost[i][RED];
        dp[i][GREEN] = min(dp[i-1][RED], dp[i-1][BLUE]) + cost[i][GREEN];
        dp[i][BLUE] = min(dp[i-1][RED], dp[i-1][GREEN]) + cost[i][BLUE];
    }

    cout << *min_element(dp[N], dp[N]+3) << '\n';

    return 0;
}
