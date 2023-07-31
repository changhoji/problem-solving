#include <iostream>
#include <utility>
using namespace std;

#define r first
#define c second

typedef pair<int, int> pll;

int count = 0;
int board[9][9];
bool findAnswer = false;

pll NextPos(pll pos){
    if(++pos.c == 9){
        pos.c = 0;
        if(++pos.r == 9) return {-1, -1};
    }
    return pos;
}

bool IsValidSudoku(pll pos, int num){
    for(int r = 0; r < 9; r++){
        if(pos.r != r && num == board[r][pos.c]) return false;
    }

    for(int c = 0; c < 9; c++){
        if(pos.c != c && num == board[pos.r][c]) return false;
    }

    for(int r = (pos.r/3)*3; r < (pos.r/3)*3 + 3; r++){
        for(int c = (pos.c/3)*3; c < (pos.c/3)*3 + 3; c++){
            if(num == board[r][c]) return false;
        }
    }
    
    return true;
}

void BackTracking(pll now){
    if(count == 0){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j];
            }
            cout << '\n';
        }
        findAnswer = true;
        return;
    }

    while(now.r != -1 && board[now.r][now.c] != 0){
        now = NextPos(now);
    }
    if(now.r == -1) return;

    for(int num = 1; num <= 9; num++){
        if(findAnswer) return;
        if(board[now.r][now.c] != 0) continue;
        if(IsValidSudoku(now, num)){
            board[now.r][now.c] = num;
            count--;
            BackTracking(NextPos(now));
            count++;
            board[now.r][now.c] = 0;
        }
    }
}

int main(){
    char num;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> num;
            if(num == '0') count++;
            board[i][j] = num - '0';
        }
    }

    BackTracking(make_pair(0, 0));

    return 0;
}
