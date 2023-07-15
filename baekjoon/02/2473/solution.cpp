#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int fix, left, right;

    int answer[3];

    ll sum = 4e9;

    for(fix = 0; fix < vec.size() - 2; fix++){
        left = fix + 1;
        right = vec.size() - 1;

        while(left < right){
            ll now = (ll)vec[fix] + vec[left] + vec[right];

            if(abs(now) < abs(sum)){
                answer[0] = vec[fix];
                answer[1] = vec[left];
                answer[2] = vec[right];
                sum = now;
            }

            if(now > 0)
                right--;
            else
                left++;
        }
    }

    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << '\n';

    return 0;
}
