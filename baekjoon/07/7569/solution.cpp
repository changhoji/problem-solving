#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H;

int dr[] = {-1, 1, 0, 0, 0, 0};
int dc[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

int tomato[100][100][100];
int day[100][100][100] = { 0,};

class Pos{
  public:
    int row;
    int col;
    int height;
    
    Pos(): row(0), col(0), height(0) {}
    Pos(int row, int col, int height): row(row), col(col), height(height) {}

    bool IsValidPos(){
        if(row < 0 || row >= N || col < 0 || col >= M || height < 0 || height >= H) return false;
        return true;
    }

    int Tomato(){
        return tomato[row][col][height];
    }

    int& Day(){
        return day[row][col][height];
    }

    Pos operator+(Pos b){
        return Pos(row+b.row, col+b.col, height+b.height);
    }
};

int main(){
    cin >> M >> N >> H;

    int unripe = 0;

    queue<Pos> q;

    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    day[i][j][k] = 0;
                    q.push(Pos(i, j, k));
                }
                else if(tomato[i][j][k] == 0){
                    day[i][j][k] = -1;
                    unripe++;
                }
                else{
                    day[i][j][k] = -1;
                }
            }
        }
    }

    int answer = 0;

    while(!q.empty()){
        Pos cur = q.front();
        q.pop();

        for(int k = 0; k < 6; k++){
            Pos npos = cur + Pos(dr[k], dc[k], dh[k]);
            if(npos.IsValidPos() && (npos.Tomato() == 0) && (npos.Day() == -1)){
                int curDay = cur.Day();
                npos.Day() = curDay + 1;
                answer = curDay + 1;
                q.push(npos);
                unripe--;
            }
        }
    }

    if(unripe) cout << "-1\n";
    else cout << answer << '\n';

    return 0;
}
