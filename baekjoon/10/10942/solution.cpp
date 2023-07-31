#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isPalindrom[2001][2001];

int AdjustPalindrom(int start, int end, vector<int> &arr){
    if(isPalindrom[start][end] != -1) return isPalindrom[start][end];

    if(start == end) return isPalindrom[start][end] = 1;

    int flag;
    if(arr[start] == arr[end]){
        flag = 1;
    } else{
        flag = 0;
    }

    if(start == end-1) return isPalindrom[start][end] = flag;

    return isPalindrom[start][end] = flag & AdjustPalindrom(start+1, end-1, arr);
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> arr(N+1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        for(int j = i; j <= N; j++){
            isPalindrom[i][j] = -1;
        }
    }

    int M;
    cin >> M;

    int S, E;
    for(int i = 0; i < M; i++){
        cin >> S >> E;
        cout << AdjustPalindrom(S, E, arr) << '\n';
    }

    return 0;
}
