#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    bool broken[10] = { false,};

    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        broken[num] = true;
    }

    int answer = 500000;
    for(int start = 0; start < 1000000; start++){
        string startString = to_string(start);

        bool flag = false;
        for(char c: startString){
            if(broken[c-'0']){
                flag = true;
                break;
            }
        }
        if(flag) continue;

        int nowCount = startString.length() + abs(N - start);
        answer = min(answer, nowCount);
    }
    answer = min(answer, abs(100 - N));

    cout << answer << '\n';

    return 0;
}
