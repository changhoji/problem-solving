#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

class Pos{
  public:
    int row;
    int col;
    int crush;

    Pos() {}
    Pos(int row, int col, int crush): row(row), col(col), crush(crush) {}
};

bool IsValidPos(int row, int col){
    return !(row < 0 || row >= N || col < 0 || col >= M);
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main(){
    cin >> N >> M;

    vector<vector<char>> map(N, vector<char>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    vector<vector<vector<int>>> time(N, vector<vector<int>>(M, vector<int>(2, 0)));

    queue<Pos> q;
    q.push(Pos(0, 0, 0));
    time[0][0][0] = 1;

    int answer = -1;

    while(!q.empty()){
        Pos cur = q.front();
        q.pop();

        if(cur.row == N-1 && cur.col == M-1){
            if(answer == -1) answer = time[cur.row][cur.col][cur.crush];
            else answer = min(answer, time[cur.row][cur.col][cur.crush]);
        }

        for(int k = 0; k < 4; k++){
            int nrow = cur.row + dr[k];
            int ncol = cur.col + dc[k];

            if(!IsValidPos(nrow, ncol)) continue;

            if(map[nrow][ncol] == '1' && cur.crush == 0){
                if(time[nrow][ncol][1] > 0) continue;
                time[nrow][ncol][1] = time[cur.row][cur.col][0] + 1;
                q.push(Pos(nrow, ncol, 1));
            }
            else if(map[nrow][ncol] == '0'){
                if(time[nrow][ncol][cur.crush] > 0) continue;
                time[nrow][ncol][cur.crush] = time[cur.row][cur.col][cur.crush] + 1;
                q.push(Pos(nrow, ncol, cur.crush));
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
