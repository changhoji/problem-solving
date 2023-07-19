#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Matrix {
    int row;
    int col;
};

int main(){
    int N;
    cin >> N;

    int dp[500][500] = { 0,}; // sart, end

    vector<Matrix> matrix(N);
    for(int i = 0; i < N; i++){
        cin >> matrix[i].row >> matrix[i].col;
    }

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int temp = 2'147'483'647;
            for(int k = i; k < j; k++){
                temp = min(temp,
                dp[i][k] + dp[k+1][j] + matrix[i].row * matrix[k].col * matrix[j].col);
            }
            dp[i][j] = temp;
        }
    }

    cout << dp[0][N-1] << '\n';

    return 0;
}