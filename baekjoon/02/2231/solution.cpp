#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int answer = 0;

    for(int i = N - 9 * to_string(N).size(); i < N; i++){
        string now = to_string(i);
        int sum = 0;
        for(char c: now){
            sum += c - '0';
        }
        if(i + sum == N){
            answer = i;
            break;
        }
    }

    cout << answer << '\n';

    return 0;
}
