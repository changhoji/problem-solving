#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> dp(N);
    vector<int> arr(N);
    vector<int> minLast(N, INF);
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        dp[i] = 1;

        int index = lower_bound(minLast.begin(), minLast.end(), arr[i]) - minLast.begin();
        dp[i] = index;
        minLast[index] = min(minLast[index], arr[i]);
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        if(minLast[i] != INF) answer = i + 1;
    }

    cout << answer << '\n';

    return 0;
}
