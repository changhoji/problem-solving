#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int answer = 0;
    int accumulate = 1;
    int cycle = 0;

    while(true){
        answer++;
        if(accumulate + cycle >= N){
            break;
        }
        accumulate += cycle;
        cycle += 6;
    }

    cout << answer << '\n';

    return 0;
}
