#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> minLast(N, INF);
    vector<int> location(N);
    int len = 0;

    for(int i = 0; i < N; i++){
        cin >> A[i];

        minLast[i] = INF;

        int index = lower_bound(minLast.begin(), minLast.end(), A[i]) - minLast.begin();
        len = max(len, index+1);
        minLast[index] = A[i];
        location[i] = index;
    }

    vector<int> lis(len);

    len;
    for(int i = location.size() - 1; i >= 0; i--){
        if(location[i] == len - 1){
            lis[--len] = A[i];
        }
    }

    cout << lis.size() << '\n';
    for(auto i: lis){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
