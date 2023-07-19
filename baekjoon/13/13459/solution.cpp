#include <iostream>
#include <vector>
using namespace std;

struct Pos {
    int row;
    int col;

    bool IsEscaped(){
        return (row == 0);
    }

    bool operator==(Pos b){
        return (row == b.row && col == b.col);
    }
};

struct Destination {
    Pos up;
    Pos right;
    Pos down;
    Pos left;
};

int answer = 0;

void SetDestination(int r, int c, vector<vector<char>> &board, Destination &d){
    int to;

    // up
    to = r;
    while(board[to][c] != '#' && board[to][c] != 'O'){
        to--;
    }
    if(board[to][c] == 'O') d.up = {0, 0};
    else d.up = {to+1, c};

    // right
    to = c;
    while(board[r][to] != '#' && board[r][to] != 'O'){
        to++;
    }
    if(board[r][to] == 'O') d.right = {0, 0};
    else d.right = {r, to-1};

    // down
    to = r;
    while(board[to][c] != '#' && board[to][c] != 'O'){
        to++;
    }
    if(board[to][c] == 'O') d.down = {0, 0};
    else d.down = {to-1, c};

    // left
    to = c;
    while(board[r][to] != '#' && board[r][to] != 'O'){
        to--;
    }
    if(board[r][to] == 'O') d.left = {0, 0};
    else d.left = {r, to+1};

    // printf("[%d][%d] => up: (%d, %d), right: (%d, %d), down: (%d, %d), left: (%d, %d)\n", r, c, d.up.row, d.up.col, d.right.row, d.right.col, d.down.row, d.down.col, d.left.row, d.left.col);
}

void Tilt(int count, Pos red, Pos blue, const vector<vector<char>> &board, vector<vector<Destination>> &dest){
    if(answer || blue.IsEscaped()) return;
    if(red.IsEscaped()){
        answer = 1;
        return;
    }
    if(count == 10) return;

    Pos newRed, newBlue;
    // up
    if((dest[red.row][red.col].up == dest[blue.row][blue.col].up) && !dest[red.row][red.col].up.IsEscaped()){
        if(red.row < blue.row){ // red located upper
            newRed = dest[red.row][red.col].up;
            newBlue = { newRed.row+1, newRed.col };
        } else{
            newBlue = dest[blue.row][blue.col].up;
            newRed = { newBlue.row+1, newBlue.col };
        }
    } else{
        newRed = dest[red.row][red.col].up;
        newBlue = dest[blue.row][blue.col].up;
    }
    Tilt(count+1, newRed, newBlue, board, dest);

    // right
    if((dest[red.row][red.col].right == dest[blue.row][blue.col].right) && !dest[red.row][red.col].right.IsEscaped()){
        if(red.col > blue.col){ // red located upper
            newRed = dest[red.row][red.col].right;
            newBlue = { newRed.row, newRed.col-1 };
        } else{
            newBlue = dest[blue.row][blue.col].right;
            newRed = { newBlue.row, newBlue.col-1 };
        }
    } else{
        newRed = dest[red.row][red.col].right;
        newBlue = dest[blue.row][blue.col].right;
    }
    Tilt(count+1, newRed, newBlue, board, dest);

    // down
    if((dest[red.row][red.col].down == dest[blue.row][blue.col].down) && !dest[red.row][red.col].down.IsEscaped()){
        if(red.row > blue.row){ // red located upper
            newRed = dest[red.row][red.col].down;
            newBlue = { newRed.row-1, newRed.col };
        } else{
            newBlue = dest[blue.row][blue.col].down;
            newRed = { newBlue.row-1, newBlue.col };
        }
    } else{
        newRed = dest[red.row][red.col].down;
        newBlue = dest[blue.row][blue.col].down;
    }
    Tilt(count+1, newRed, newBlue, board, dest);

    // left
    if((dest[red.row][red.col].left == dest[blue.row][blue.col].left) && !dest[red.row][red.col].left.IsEscaped()){
        if(red.col < blue.col){ // red located upper
            newRed = dest[red.row][red.col].left;
            newBlue = { newRed.row, newRed.col+1 };
        } else{
            newBlue = dest[blue.row][blue.col].left;
            newRed = { newBlue.row, newBlue.col+1 };
        }
    } else{
        newRed = dest[red.row][red.col].left;
        newBlue = dest[blue.row][blue.col].left;
    }
    Tilt(count+1, newRed, newBlue, board, dest);
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M));
    vector<vector<Destination>> dest(N, vector<Destination>(M));

    Pos red, blue;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                red = { i, j };
            } else if(board[i][j] == 'B'){
                blue = { i, j };
            }
        }
    }

    for(int r = 1; r < N-1; r++){
        dest[r].resize(M);
        for(int c = 1; c < M-1; c++){
            SetDestination(r, c, board, dest[r][c]);
        }
    }

    Tilt(0, red, blue, board, dest);

    cout << answer << '\n';

    return 0;
}
