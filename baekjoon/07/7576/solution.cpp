#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int tomato[1000][1000];
int day[1000][1000];

class Pos{
  public:
    int row;
    int col;
    
    Pos(): row(0), col(0) {}
    Pos(int row, int col): row(row), col(col) {}

    bool IsValidPos(){
        if(row < 0 || row >= N || col < 0 || col >= M) return false;
        return true;
    }

    int Tomato(){
        return tomato[row][col];
    }

    int& Day(){
        return day[row][col];
    }

    Pos operator+(Pos b){
        return Pos(row+b.row, col+b.col);
    }
};

int main(){
    cin >> M >> N;;

    int unripe = 0;

    queue<Pos> q;


    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1){
                day[i][j] = 0;
                q.push(Pos(i, j));
            }
            else if(tomato[i][j] == 0){
                day[i][j] = -1;
                unripe++;
            }
            else{
                day[i][j] = -1;
            }
        }
    }

    int answer = 0;

    while(!q.empty()){
        Pos cur = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            Pos npos = cur + Pos(dr[k], dc[k]);
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
