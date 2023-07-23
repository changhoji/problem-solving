#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);
    int num;
    cin >> num;
    triangle[0].push_back(num);

    for(int i = 1; i < n; i++){
        triangle[i].resize(i+1);
        for(int j = 0; j <= i; j++){
            cin >> num;
            if(j == 0){
                triangle[i][j] = triangle[i-1][0] + num;
            } else if(j == i){
                triangle[i][j] = triangle[i-1][j-1] + num;
            } else{
                triangle[i][j] = max(triangle[i-1][j-1], triangle[i-1][j]) + num;
            }
        }
    }

    cout << *max_element(triangle[n-1].begin(), triangle[n-1].end()) << '\n';

    return 0;
}
