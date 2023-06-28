#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    bool used[1000] = { false,};

    vector<int> josephus;

    int lastIndex = -1;
    int nowIndex = lastIndex;
    int validCount;

    for(int i = 0; i < N; i++){
        validCount = 0;
        while(validCount < K){
            nowIndex = (nowIndex + 1) % N;
            if(!used[nowIndex]){
                validCount++;
            }
        }
        josephus.push_back(nowIndex+1);
        used[nowIndex] = true;
        lastIndex = nowIndex;
    }

    cout << '<';
    for(int i = 0; i < N; i++){
        cout << josephus[i];
        if(i != N-1)
            cout << ", ";
    }
    cout << ">\n";

    return 0;
}
