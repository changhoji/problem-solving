#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> vec(N);

    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int left = 0;
    int right = vec.size() - 1;

    int first;
    int second;
    int sum = 2'147'000'000;

    while(left < right){
        int now = vec[left] + vec[right];

        if(abs(now) < abs(sum)){
            first = vec[left];
            second = vec[right];
            sum = now;
        }

        if(now > 0)
            right--;
        else
            left++;
    }

    cout << first << ' ' << second << '\n';

    return 0;
}
