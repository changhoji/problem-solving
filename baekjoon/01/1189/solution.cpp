#include <iostream>
#include <vector>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int answer = 0;
int R, C, K;
char ground[5][5];

void DFS(int r, int c, int distance, vector<vector<bool>> &visited){
    // printf("r = %d, c = %d, depth = %d\n", r, c, distance);
    if(r == 0 && c == C-1){
        if(distance == K) answer++;
        return;
    }

    int nrow, ncol;
    for(int k = 0; k < 4; k++){
        nrow = r + dr[k];
        ncol = c + dc[k];

        if(nrow < 0 || nrow >= R || ncol < 0 || ncol >= C) continue;

        if(visited[nrow][ncol] == false && ground[nrow][ncol] == '.'){
            visited[nrow][ncol] = true;
            DFS(nrow, ncol, distance+1, visited);
            visited[nrow][ncol] = false;
        }
    }
}

int main(){
    cin >> R >> C >> K;
    
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cin >> ground[r][c];
        }
    }

    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[R-1][0] = true;

    DFS(R-1, 0, 1, visited);

    cout << answer << '\n';

    return 0;
}
