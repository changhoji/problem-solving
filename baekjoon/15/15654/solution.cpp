#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[8];
int used[8] = { 0,};
vector<int> num;

void BackTracking(int depth){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int next = 0; next < N; next++){
        if(used[next] == 0){
            arr[depth] = num[next];
            used[next] = 1;
            BackTracking(depth+1);
            used[next] = 0;
        }
    }
}

int main(){
    cin >> N >> M;

    num.resize(N);
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    BackTracking(0);

    return 0;
}
