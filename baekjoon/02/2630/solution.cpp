#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Count{
  public:
    int white;
    int blue;

    Count(): white(0), blue(0) {}
    Count(int white, int blue): white(white), blue(blue) {}

    Count& operator+=(const Count b){
        this->white += b.white;
        this->blue += b.blue;
        return *this;
    }
};

Count MakePaper(int N, int r, int c, vector<vector<int>> &paper){
    Count count;

    int size = 1 << N;
    int stride = 1 << (N - 1);

    int white = 0;
    int blue = 0;
    
    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            if(paper[i][j] == 0) white++;
            else blue++;
        }
    }

    if(white == size*size){
        count.white = 1;
    }
    else if(blue == size*size){
        count.blue = 1;
    }
    else{       
        count += MakePaper(N-1, r, c, paper);
        count += MakePaper(N-1, r, c+stride, paper);
        count += MakePaper(N-1, r+stride, c, paper);
        count += MakePaper(N-1, r+stride, c+stride, paper);
    }

    return count;
}

int main(){
    int N;
    cin >> N;

    N = (int)log2(N);

    vector<vector<int>> paper((1 << N), vector<int>(1 << N));

    for(int i = 0; i < (1 << N); i++){
        for(int j = 0; j < (1 << N); j++){
            cin >> paper[i][j];
        }
    }

    Count answer = MakePaper(N, 0, 0, paper);

    cout << answer.white << '\n' << answer.blue << '\n';

    return 0;
}
