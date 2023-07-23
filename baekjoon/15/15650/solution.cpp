#include <iostream>
using namespace std;

int N, M;
int arr[8];

void BackTracking(int depth, int start){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int next = start; next <= N; next++){
        arr[depth] = next;
        BackTracking(depth+1, next+1);
    }
}

int main(){
    cin >> N >> M;

    BackTracking(0, 1);

    return 0;
}