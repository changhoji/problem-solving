#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
int R, C;

struct Pos{
    int row;
    int col;

    Pos() {}
    Pos(int row, int col): row(row), col(col) {}

    bool IsValidPos(){
        return !(row < 0 || row >= R || col < 0 || col >= C);
    }

    Pos& operator+=(Pos b){
        this->row += b.row;
        this->col += b.col;
        return *this;
    }

    Pos operator+(Pos b){
        return Pos(row + b.row, col + b.col);
    }
};

Pos dpos[] = {Pos(-1, 0), Pos(1, 0), Pos(0, -1), Pos(0, 1)};

void DFS(Pos start, vector<vector<char>> &board, vector<bool> &visited, int count){
    answer = max(answer, count);

    Pos npos;
    for(int k = 0; k < 4; k++){
        npos = start + dpos[k];
        if(npos.IsValidPos()){
            char next = board[npos.row][npos.col];
            if(visited[next - 'A']) continue;

            visited[next - 'A'] = true;
            DFS(npos, board, visited, count+1);
            visited[next - 'A'] = false;
        }
    }
}

int main(){
    cin >> R >> C;

    vector<vector<char>> board(R, vector<char>(C));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }

    vector<bool> visited(26, false);
    visited[board[0][0] - 'A'] = true;

    DFS(Pos(0, 0), board, visited, 1);

    cout << answer << '\n';

    return 0;
}
 