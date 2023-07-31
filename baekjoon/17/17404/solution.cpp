#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

enum Color {RED, GREEN, BLUE};

int main(){
    int N;
    cin >> N;

    int cost[1001][3];
    int dp[1001][3];

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            cin >> cost[i][j];
        }
    }

    int answer = INF;

    for(int start = 0; start < 3; start++){
        for(int i = 0; i < 3; i++){ // for setting dp[1]
            if(start == i){
                dp[1][i] = cost[1][i];
            } else{
                dp[1][i] = INF;
            }
        }

        for(int i = 2; i <= N; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }

        for(int end = (start+1)%3; end != start; end = (end+1)%3){
            answer = min(answer, dp[N][end]);
        }
    }

    cout << answer << '\n';

    return 0;
}
