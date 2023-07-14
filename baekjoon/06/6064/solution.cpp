#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(b) return GCD(b, a % b);
    return a;
}

int LCM(int a, int b){
    return a * b / GCD(a,b);
}

int main(){
    cin.tie(0) -> ios::sync_with_stdio(false);

    int T;
    cin >> T;

    int M, N, x, y;
    for(int tc = 1; tc <= T; tc++){
        cin >> M >> N >> x >> y;

        int year = x;
        int nowY = (x - 1) % N + 1;
        
        int lcm = LCM(M, N);
        while(true){
            if(year > lcm){
                year = -1;
                break;
            }
            if(nowY == y){
                break;
            }
            nowY = (nowY + M - 1) % N + 1;
            year += M;
        }
        
        cout << year << '\n';
    }

    return 0;
}
