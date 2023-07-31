#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

typedef pair<int, int> pll;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<pll> lines;

    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        lines.push_back(make_pair(a, b));    
    }

    sort(lines.begin(), lines.end());

    vector<int> minLast(N, INF);
    vector<int> location(N);

    int len = -1;
    for(int i = 0; i < N; i++){
        int index = lower_bound(minLast.begin(), minLast.end(), lines[i].second) - minLast.begin();

        len = max(len, index);
        minLast[index] = lines[i].second;
        location[i] = index;
    }

    vector<int> answer(N-len-1);

    int idx = N-len-2;
    for(int i = N-1; i >= 0; i--){
        if(len == location[i]){
            len--;
        } else{
            answer[idx--] = lines[i].first;
        }
    }

    cout << answer.size() << '\n';
    for(auto i: answer){
        cout << i << '\n';
    }

    return 0;
}
