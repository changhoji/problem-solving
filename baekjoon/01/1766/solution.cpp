#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int A, B;

    int in[32001] = { 0,};
    vector<int> out[32001];
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        out[A].push_back(B);
        in[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= N; i++){
        if(in[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int now = pq.top();
        pq.pop();

        cout << now << ' ';

        for(int next: out[now]){
            if(--in[next] == 0) pq.push(next);
        }
    }
    cout << '\n';

    return 0;
}
