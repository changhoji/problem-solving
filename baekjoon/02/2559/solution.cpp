#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = K - 1;

    int answer = -1e7;

    int sum = 0;
    for(int i = 0; i < K; i++){
        sum += arr[i];
    }

    while(right < N){
        answer = max(answer, sum);
        sum += arr[++right];
        sum -= arr[left++];
    }

    cout << answer << '\n';

    return 0;
}
