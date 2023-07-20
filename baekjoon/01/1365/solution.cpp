#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int main(){
    int N;
    cin >> N;

    vector<int> line(N+1);
    vector<int> minLast(N+1, INF);

    int len = 0;
    for(int i = 1; i <= N; i++){
        cin >> line[i];

        int idx = lower_bound(minLast.begin()+1 ,minLast.end(), line[i]) - minLast.begin();
        minLast[idx] = line[i];
        len = max(len, idx);
    }

    cout << N - len << '\n';

    return 0;
}
