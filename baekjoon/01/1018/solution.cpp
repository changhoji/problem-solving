#include <iostream>
using namespace std;

int main(){
    int N, M;
    char board[50][50];

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    int min_cnt = 32;

    for(int i = 0; i < N-7; i++){
        for(int j = 0; j < M-7; j++){
            // start at the pos where can get 8x8 size
            
            int cnt = 0;
            for(int r = i; r < i+8; r++){
                for(int c = j; c < j+8; c++){
                    if(((r+c)%2 == 0) && board[r][c] == 'W') cnt++;
                    if(((r+c)%2 == 1) && board[r][c] == 'B') cnt++;
                }
            }
            if(cnt > 32) cnt = 64 - cnt;
            if(min_cnt > cnt) min_cnt = cnt;
        }
    }

    cout << min_cnt << '\n';

    return 0;
}
