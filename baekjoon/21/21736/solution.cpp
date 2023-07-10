#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
    int row;
    int col;
};

int answer = 0;

int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};

void BFS(int N, int M, Pos pos, vector<vector<char>> &campus){
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[pos.row][pos.col] = true;
    
    queue<Pos> q;
    q.push(pos);

    while(!q.empty()){
        Pos cur = q.front();
        q.pop();

        if(campus[cur.row][cur.col] == 'P') answer++;

        for(int k = 0; k < 4; k++){
            int nrow = cur.row + drow[k];
            int ncol = cur.col + dcol[k];

            if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= M) continue;

            if(campus[nrow][ncol] != 'X' && visited[nrow][ncol] == false){
                visited[nrow][ncol] = true;
                q.push({nrow, ncol});
            }
        }
    }   
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<char>> campus(N, vector<char>(M));

    int r, c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                r = i;
                c = j;
            }
        }
    }

    BFS(N, M, {r, c}, campus);

    if(answer) cout << answer << '\n';
    else cout << "TT\n";

    return 0;
}
