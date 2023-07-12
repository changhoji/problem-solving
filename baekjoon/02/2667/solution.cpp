#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int cnt = 0;

void DFS(int row, int col, int N, char (*map)[25], bool (*visited)[25]){
    cnt++;

    for(int k = 0; k < 4; k++){
        int nrow = row + dr[k];
        int ncol = col + dc[k];

        if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N) continue;

        if(visited[nrow][ncol] == false && map[nrow][ncol] == '1'){
            visited[nrow][ncol] = true;
            DFS(nrow, ncol, N, map, visited);
        }
    }
}

int main(){
    int N;
    cin >> N;

    char map[25][25];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    vector<int> answer;
    bool visited[25][25] = { false,};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == false && map[i][j] == '1'){
                cnt = 0;
                visited[i][j] = true;
                DFS(i, j, N, map, visited);
                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(auto i: answer){
        cout << i << '\n';
    }

    return 0;
}
