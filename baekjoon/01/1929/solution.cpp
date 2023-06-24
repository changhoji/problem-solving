#include <iostream>
#include <vector>
using namespace std;

void Filter(vector<int> &nums, int n, int N){
    for(int i = n; i <= N; i += n){
        nums[i] = 1;
    }
}

int main(){
    int M, N;
    cin >> M >> N;

    vector<int> nums(N+1);

    for(int num = 2; num <= N; num++){
        if(nums[num] == 0){
            if(num >= M)
                cout << num << '\n';
            Filter(nums, num, N);
        }
    }
    
    return 0;
}
