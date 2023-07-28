#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2147000000

int main(){
    int N;
    cin >> N;

    int lisLength = 0;
    vector<int> A(N);
    vector<int> minLast(N, INF);
    vector<int> location(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        
        int index = lower_bound(minLast.begin(), minLast.end(), A[i]) - minLast.begin();
        lisLength = max(lisLength, index+1);
        minLast[index] = A[i];
        location[i] = index+1;
    }

    cout << lisLength << '\n';

    vector<int> lis(lisLength);
    for(int i = N-1; i >= 0; i--){
        if(lisLength == location[i]){
            lis[--lisLength] = A[i];
        }
    }

    for(auto i: lis){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
