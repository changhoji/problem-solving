#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int MaximumHeight(vector<int> &tree, int M){
    ll left = 0;
    ll right = 2'000'000'000;
    ll answer;
    ll mid;
    while(left <= right){
        mid = (left + right) / 2;

        ll sum = 0;
        for(int h: tree){
            sum += max((ll)0, h-mid);
        }
        if(sum < M){
            right = mid - 1;
        }
        else{
            answer = mid;
            left = mid + 1;
        }
    }

    return (int)answer;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> tree(N);
    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }

    cout << MaximumHeight(tree, M) << '\n';

    return 0;
}
