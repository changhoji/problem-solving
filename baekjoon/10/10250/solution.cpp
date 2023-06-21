#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++){
        int H, W, N;
        cin >> H >> W >> N;

        int x, y;
        y = (N-1) % H + 1;
        x = (N-1) / H + 1;

        cout << y*100 + x << '\n';
    }

    return 0;
}
