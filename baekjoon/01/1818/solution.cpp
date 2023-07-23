#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int main(){
    int N;
    cin >> N;

    vector<int> book(N);
    vector<int> minLast(N, INF);

    int len = 0;
    for(int i = 0; i < N; i++){
        cin >> book[i];

        int index = lower_bound(minLast.begin(), minLast.end(), book[i]) - minLast.begin();
        minLast[index] = book[i];

        len = max(len, index+1);
    }

    cout << N - len << '\n';

    return 0;
}
