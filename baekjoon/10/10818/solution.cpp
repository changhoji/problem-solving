#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> nums(N);

    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    cout << *min_element(nums.begin(), nums.end()) << " " << *max_element(nums.begin(), nums.end()) << '\n';

    return 0;
}
