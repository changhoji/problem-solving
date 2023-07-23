#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int answer = 0;

struct Pos{
    int row;
    int col;

    Pos() {}
    Pos(int row, int col): row(row), col(col) {}

    bool IsValidPos(){
        return !(row < 0 || row >= N || col < 0 || col >= M);
    }

    Pos operator++(int){
        Pos temp(row, col);

        col++;
        if(col == M){
            row++;
            col = 0;
        }

        return temp;
    }

    Pos operator+(Pos b){
        return Pos(row + b.row, col + b.col);
    }

    Pos operator+(int b){
        Pos result(row, col);

        result.col += b;
        result.row += (result.col / M);
        result.col %= M;

        return result;
    }
};

Pos dpos[] = {Pos(-1, 0), Pos(1, 0), Pos(0, -1), Pos(0, 1)};

int SafetyZoneSize(vector<vector<int>> &temp){
    vector<vector<int>> map(temp);

    queue<Pos> q;
    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 2){
                q.push(Pos(i, j));
            } else if(map[i][j] == 0){
                result++;
            }
        }
    }

    while(!q.empty()){
        Pos cur = q.front();
        q.pop();
        
        Pos npos;
        for(int k = 0; k < 4; k++){
            npos = cur + dpos[k];
            if(npos.IsValidPos() && map[npos.row][npos.col] == 0){
                map[npos.row][npos.col] = 2;
                result--;
                q.push(npos);
            }
        }
    }

    return result;
}

void SetWall(int depth, Pos start, vector<vector<int>> &map){
    if(depth == 3){
        answer = max(answer, SafetyZoneSize(map));
        return;
    }

    for(Pos pos = start; pos.IsValidPos(); pos++){
        if(map[pos.row][pos.col] == 0){
            map[pos.row][pos.col] = 1;
            SetWall(depth+1, pos+1, map);
            map[pos.row][pos.col] = 0;
        }
    }
}

int main(){
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
         
            cin >> map[i][j];
        }
    }

    SetWall(0, Pos(0, 0), map);

    cout << answer << '\n';

    return 0;
}
