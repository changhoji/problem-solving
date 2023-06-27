#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LowerBound(const vector<int> &nums, int key){
    int left = 0;
    int right = nums.size();

    while(left < right){
        int mid = (left + right) / 2;
        if(mid == nums.size()) break;

        if(nums[mid] < key)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int UpperBound(const vector<int> &nums, int key){
    int left = 0;
    int right = nums.size();

    while(left < right){
        int mid = (left + right) / 2;
        if(mid == nums.size()) break;

        if(nums[mid] <= key)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N, M;
    cin >> N;
    
    vector<int> nums(N);
    for(int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    cin >> M;

    int key;
    for(int i = 0; i < M; i++){
        cin >> key;

        int lower = LowerBound(nums, key);
        int upper = UpperBound(nums, key);

        cout << upper - lower << ' ';
    }
    cout << '\n';

    return 0;
}
