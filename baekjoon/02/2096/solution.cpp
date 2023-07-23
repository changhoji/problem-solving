#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    int num[2][3];
    int maxDP[2][3];
    int minDP[2][3];

    cin >> num[0][0] >> num[0][1] >> num[0][2];
    for(int i = 0; i < 3; i++){
        maxDP[0][i] = num[0][i];
        minDP[0][i] = num[0][i];
    }

    for(int i = 1; i < N; i++){
        int now = i % 2;
        int before = (now == 1) ? 0 : 1;

        cin >> num[now][0] >> num[now][1] >> num[now][2];    

        maxDP[now][0] = max(maxDP[before][0], maxDP[before][1]) + num[now][0];
        minDP[now][0] = min(minDP[before][0], minDP[before][1]) + num[now][0];

        maxDP[now][1] = max(max(maxDP[before][0], maxDP[before][1]), maxDP[before][2]) + num[now][1];
        minDP[now][1] = min(min(minDP[before][0], minDP[before][1]), minDP[before][2]) + num[now][1];

        maxDP[now][2] = max(maxDP[before][1], maxDP[before][2]) + num[now][2];
        minDP[now][2] = min(minDP[before][1], minDP[before][2]) + num[now][2];
    }

    int idx = (N - 1) % 2;
    cout << *max_element(maxDP[idx], maxDP[idx]+3) << ' ' << *min_element(minDP[idx], minDP[idx]+3) << '\n';

    return 0;
}
