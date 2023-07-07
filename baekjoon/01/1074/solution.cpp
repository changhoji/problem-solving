#include <iostream>
#include <vector>
using namespace std;

void Z(int N, int row, int col, int r, int c, int count){

    if(row == r && col == c){
        cout << count << '\n';
        return;
    }


    int stride = 1 << (N - 1);

    if(r < row+stride && c < col+stride){
        Z(N-1, row, col, r, c, count);
        return;
    }
    
    count += stride*stride;

    if(r < row+stride && c < col+2*stride){
        Z(N-1, row, col+stride, r, c, count);
        return;
    }

    count += stride*stride;

    if(r < row+2*stride && c < col+stride){
        Z(N-1, row+stride, col, r, c, count);
        return;
    }
    
    count += stride*stride;

    if(r < row+2*stride && c < col+2*stride){
        Z(N-1, row+stride, col+stride, r, c, count);
        return;
    }
}

int main(){
    int N, r, c;
    cin >> N >> r >> c;


    Z(N, 0, 0, r, c, 0);
    
    return 0;
}
