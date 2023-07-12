#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> dp(N+1);
    vector<int> score(N+1);

    dp[0] = 0;

    cin >> score[1];
    dp[1] = score[1];

    cin >> score[2];
    dp[2] = score[2] + score[1];

    for(int i = 3; i <= N; i++){
        cin >> score[i];
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }
    
    cout << dp[N] << '\n';

    return 0;
}
