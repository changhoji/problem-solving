#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> out[1001];
int in[1001] = { 0,};

int main(){
    int N, M;
    cin >> N >> M;

    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            if(j != 0){
                out[c].push_back(b);
                ++in[b];
            }
            c = b;
        }
    }

    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(!in[i]) q.push(i);
    }

    vector<int> answer;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        answer.push_back(cur);

        for(int next: out[cur]){
            if(--in[next] == 0){
                q.push(next);
            }
        }
    }

    if(answer.size() == N){
        for(auto i: answer){
            cout << i << '\n';
        }
    } else{
        cout << "0\n";
    }

    return 0;
}
