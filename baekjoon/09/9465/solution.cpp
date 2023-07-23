#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int n;
        cin >> n;

        vector<int> score[2];
        vector<int> dp[2];
        dp[0].resize(n);
        dp[1].resize(n);

        int num;

        for(int i = 0; i < n; i++){
            cin >> num;
            score[0].push_back(num);
        }
        for(int i = 0; i < n; i++){
            cin >> num;
            score[1].push_back(num);
        }

        dp[0][0] = score[0][0];
        dp[1][0] = score[1][0];

        if(n >= 2){
            dp[0][1] = score[1][0] + score[0][1];
            dp[1][1] = score[0][0] + score[1][1];
        }

        for(int i = 2; i < n; i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + score[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + score[1][i];
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }

    return 0;
}
