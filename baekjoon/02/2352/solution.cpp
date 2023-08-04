#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int main(){
    int n;
    cin >> n;

    int port;
    vector<int> minLast(n, INF);
    int answer = 0;
    for(int i = 0; i < n; i++){
        cin >> port;
        
        int index = lower_bound(minLast.begin(), minLast.end(), port) - minLast.begin();
        answer = max(answer, index+1);
        minLast[index] = port;
    }

    cout << answer << '\n';

    return 0;
}
