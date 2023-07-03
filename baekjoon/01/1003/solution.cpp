#include <iostream>
#include <vector>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b){
    return make_pair(a.first+b.first, a.second+b.second);
}

pair<int, int> Fibonacci(int n, vector<pair<int, int>> &pairs){
    if(n == 0) return pairs[0];
    if(n == 1) return pairs[1];
    
    if(pairs[n] == make_pair(0, 0)){
        return pairs[n] = Fibonacci(n-1, pairs) + Fibonacci(n-2, pairs);
    }

    return pairs[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    
    vector<pair<int, int>> pairs(40, make_pair(0, 0));
    pairs[0] = make_pair(1, 0);
    pairs[1] = make_pair(0, 1);

    int T, N;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        cin >> N;

        pair<int, int> answer = Fibonacci(N, pairs);
        cout << answer.first << " " << answer.second << "\n";
    }

    return 0;
}
