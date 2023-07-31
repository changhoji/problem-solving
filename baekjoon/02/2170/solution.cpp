#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pll;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pll> vec;

    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end());

    int start = -1e9-1;
    int end = -1e9-1;

    int answer = 0;

    for(auto p: vec){
        if(p.first > end){
            answer += end - start;
            start = p.first;
        }
        end = max(p.second, end);
    }
    answer += end - start;

    cout << answer << '\n';

    return 0;
}
