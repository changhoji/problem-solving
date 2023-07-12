#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};

struct Pos{
    int row;
    int col;
};

int IsValidPos(int N, int M, Pos pos){
    return !(pos.row < 0 || pos.row >= N || pos.col < 0 || pos.col >= M);
}

int MinimumTime(vector<vector<char>> &maze){
    int N = maze.size();
    int M = maze[0].size();

    vector<vector<int>> time(N, vector<int>(M, 0));
    time[0][0] = 1;

    queue<Pos> q;
    q.push({0, 0});

    while(!q.empty()){
        Pos cur = q.front();
        q.pop();

        if(cur.row == N-1 && cur.col == M-1) return time[N-1][M-1];

        for(int k = 0; k < 4; k++){
            int nrow = cur.row + drow[k];
            int ncol = cur.col + dcol[k];

            if(IsValidPos(N, M, {nrow, ncol}) && time[nrow][ncol] == 0 && maze[nrow][ncol] == '1'){
                time[nrow][ncol] = time[cur.row][cur.col] + 1;
                q.push({nrow, ncol});
            }
        }
    }

    return 0;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<char>> maze(N, vector<char>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> maze[i][j];
        }
    }

    cout << MinimumTime(maze) << '\n';

    return 0;
}
