#include <iostream>
using namespace std;

#define DIV 1'000'000'000

typedef long long ll;


ll solve(int N){
    ll dp[101][10][1 << 10] = { 0,};
    for(int i = 1; i <= 9; ++i){
        dp[1][i][1 << i] = 1;
    }

    for(int i = 2; i <= N; ++i){
        for(int now = 0; now <= 9; ++now){
            for(int mask = 0; mask < (1<<10); ++mask){
                int nMask = mask | (1 << now);
                if(now == 0){
                    dp[i][now][nMask] += dp[i-1][1][mask];
                    dp[i][now][nMask] %= DIV;
                } else if(now == 9){
                    dp[i][now][nMask] += dp[i-1][8][mask];
                    dp[i][now][nMask] %= DIV;
                } else{
                    dp[i][now][nMask] += dp[i-1][now-1][mask];
                    dp[i][now][nMask] %= DIV;

                    dp[i][now][nMask] += dp[i-1][now+1][mask];
                    dp[i][now][nMask] %= DIV;
                }
            }
        }
    }

    ll answer = 0;
    for(int now = 0; now <= 9; ++now){
        answer = (answer + dp[N][now][(1 << 10) - 1]);
    }

    return answer;
}

int main(){
    int N;
    cin >> N;

    cout << solve(N) << '\n';

    return 0;
}
