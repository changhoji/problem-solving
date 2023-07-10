#include <iostream>
using namespace std;

int N, M;

char before[50][50];
char after[50][50];

void flip(int row, int col){
    for(int r = row; r < row+3; r++){
        for(int c = col; c < col+3; c++){
            before[r][c] = (before[r][c] == '1') ? '0' : '1';
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> before[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> after[i][j];

    int answer = 0;

    for(int i = 0; i < N-2; i++){
        for(int j = 0; j < M-2; j++){
            if(before[i][j] != after[i][j]){
                answer++;
                flip(i, j);
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(before[i][j] != after[i][j]){
                answer = -1;
                break;
            }
        }
        if(!~answer) break;
    }

    cout << answer << '\n';

    return 0;
}
