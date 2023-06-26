#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> cards(N);

    for(int i = 0; i < N; i++){
        cin >> cards[i];
    }

    int answer = 3;
    int sum;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(i == j || j == k || k == i) continue;
                sum = cards[i] + cards[j] + cards[k];
                if(sum > M) continue;
                if(answer < sum) answer = sum;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
