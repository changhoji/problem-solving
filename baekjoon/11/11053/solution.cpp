#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int dp[1000] = { 0,};
    dp[0] = 1;
    int arr[1000];
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];

        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]) dp[i] = max(dp[j]+1, dp[i]);
        }

        if(dp[i] == 0) dp[i] = 1;
    }

    cout << *max_element(dp, dp+N) << '\n';

    return 0;
}
