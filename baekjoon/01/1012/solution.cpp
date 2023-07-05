#include <iostream>
#include <cstring>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void DFS(int row, int col, int N, int M, int (*ground)[50], bool (*visited)[50]){
    for(int k = 0; k < 4; k++){
        int nrow = row + dr[k];
        int ncol = col + dc[k];

        if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= M) continue;

        if(visited[nrow][ncol] == false && ground[nrow][ncol] == 1){
            visited[nrow][ncol] = true;
            DFS(nrow, ncol, N, M, ground, visited);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int M, N, K;
        cin >> M >> N >> K;

        int ground[50][50] = { 0,};
        bool visited[50][50] = { 0,};

        for(int i = 0; i < K; i++){
            int r, c;
            cin >> c >> r;
            ground[r][c] = 1;
        }

        int answer = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visited[i][j] == false && ground[i][j] == 1){
                    visited[i][j] = true;
                    DFS(i, j, N, M, ground, visited);
                    answer++;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
