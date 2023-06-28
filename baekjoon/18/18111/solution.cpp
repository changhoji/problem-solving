#include <iostream>
using namespace std;

int CalculateTime(int (*height)[500], int total, int targetHeight, int N, int M, int B){
    if(targetHeight * N * M > total + B) return -1;

    int takenTime = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(height[i][j] > targetHeight){
                int diff = height[i][j] - targetHeight;
                B += diff;
                takenTime += diff * 2;
            }
            else if(height[i][j] < targetHeight){
                int diff = targetHeight - height[i][j];
                B -= diff;
                takenTime += diff;
            }
        }
    }

    return takenTime;
}

int main(){
    int N, M, B;
    cin >> N >> M >> B;

    int height[500][500];
    int total = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> height[i][j];
            total += height[i][j];
        }
    }

    int minTime = 987654321;
    int possibleMaxHeight = 0;
    int temp;

    for(int targetHeight = 256; targetHeight >= 0; targetHeight--){
        if((temp = CalculateTime(height, total, targetHeight, N, M, B)) == -1)
            continue;
        if(minTime > temp){
            minTime = temp;
            possibleMaxHeight = targetHeight;
        }
    }
    
    cout << minTime << ' ' << possibleMaxHeight << '\n';

    return 0;
}           
