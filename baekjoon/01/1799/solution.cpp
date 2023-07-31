#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define r first
#define c second

typedef pair<int, int> pll;

int N;
int result = 0;
int board[10][10];

pll NextPos(pll p){
    if(p.r == N) return {-1, -1};
    if(++p.c == N){
        p.c = 0;
        if(++p.r == N) return {-1, -1};
    }
    return p;
}

bool PossiblePos(int row, int col){
    int left, right;

    left = right = col;
    for(int r = row-1; r >= 0; r--){
        left--;
        right++;
        if(left >= 0 && board[r][left] == 2) return false;
        if(right < N && board[r][right] == 2) return false;
    }

    left = right = col;
    for(int r = row+1; r < N; r++){
        left--;
        right++;
        if(left >= 0 && board[r][left] == 2) return false;
        if(right < N && board[r][right] == 2) return false;
    }

    return true;
}

void BackTracking(int depth, int r, int c){
    result = max(result, depth);

    pll now = {r, c};
    while((now = NextPos(NextPos(now))).r != -1){
        if(N%2 == 0){
            if(now.c == 0) now.c++;
            else if(now.c == 1) now.c--;
        }
        if(board[now.r][now.c] == 0) continue;
        if(PossiblePos(now.r, now.c)){
            board[now.r][now.c] = 2;
            BackTracking(depth+1, now.r, now.c);
            board[now.r][now.c] = 1;
        }
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    result = 0;
    BackTracking(0, 0, -2);

    int temp = result;
    result = 0;
    BackTracking(0, 0, -1);

    cout << result + temp << '\n';

    return 0;
}
