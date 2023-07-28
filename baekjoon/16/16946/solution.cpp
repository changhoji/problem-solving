#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define r first
#define c second

#define WALL 987654321

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

typedef pair<int, int> pii;

int map[1000][1000];
pii par[1000][1000];

int main(){
    int N, M;
    cin >> N >> M;

    char c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> c;
            map[i][j] = c - '0';
            if(map[i][j] == 1) map[i][j] = WALL;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] != 0) continue;
            int size = 0;
            queue<pii> visited;
            queue<pii> q;

            q.push(make_pair(i, j));
            map[i][j] = 1;

            pii p = make_pair(i, j);

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                size++;
                visited.push(cur);

                for(int k = 0; k < 4; k++){
                    int nr = cur.r + dr[k];
                    int nc = cur.c + dc[k];

                    if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

                    if(map[nr][nc] == 0){
                        map[nr][nc] = 1;
                        q.push(make_pair(nr, nc));
                        visited.push(make_pair(nr, nc));
                    }
                }
            }
            
            while(!visited.empty()){
                auto cur = visited.front();
                visited.pop();

                map[cur.r][cur.c] = size;
                par[cur.r][cur.c] = p;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == WALL){
                vector<pii> side;
                int sum = 1;
                for(int k = 0; k < 4; k++){
                    int nr = i+dr[k];
                    int nc = j+dc[k];

                    if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    if(map[nr][nc] == WALL) continue;

                    if(find(side.begin(), side.end(), par[nr][nc]) != side.end())
                        continue;

                    side.push_back(par[nr][nc]);
                    sum += map[nr][nc];
                }
                cout << sum%10;
            } else{
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}
