#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> coordinates;

    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }

    sort(coordinates.begin(), coordinates.end());

    for(auto p: coordinates){
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
