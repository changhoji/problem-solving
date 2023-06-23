#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int M = 0, score, sumScore = 0;
    for(int i = 0; i < N; i++){
        cin >> score;

        if(score > M) M = score;
        sumScore += score;
    }

    cout << ((double)sumScore/N) / M * 100 << '\n';

    return 0;
}
