#include <iostream>
#include <vector>
using namespace std;

int N;

vector<int> sequence;
vector<int> used;

void BackTracking(int now, int depth){
    if(depth == N){
        for(auto i: sequence){
            cout << i << ' ';
        }
        cout << '\n';
    }

    for(int next = 1; next <= N; next++){
        if(!used[next]){
            used[next] = true;
            sequence.push_back(next);
            BackTracking(now+1, depth+1);
            used[next] = false;
            sequence.pop_back();
        }
    }
}

int main(){
    cin >> N;

    used = vector<int>(N+1, false);
    
    BackTracking(0, 0);

    return 0;
}
