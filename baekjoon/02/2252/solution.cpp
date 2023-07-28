#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int in[32001] = { 0,};
    vector<int> out[32001];

    int A, B;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        in[B]++;
        out[A].push_back(B);
    }

    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for(int next: out[cur]){
            if(--in[next] == 0) q.push(next);
        }
    }
    cout << '\n';

    return 0;
}
