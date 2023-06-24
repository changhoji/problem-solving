#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &nums, int key){
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        
        if(nums[mid] < key){
            left = mid + 1;
        } else if(nums[mid] > key){
            right = mid - 1;
        } else{
            return mid;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> nums(N);

    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int M, key;
    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> key;
        int result = BinarySearch(nums, key);

        if(result == -1)
            cout << "0\n";
        else
            cout << "1\n";
    }

    return 0;
}
