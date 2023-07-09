#include <iostream>
#include <vector>
using namespace std;

int MindDistance(int a, int b){
    int temp = a ^ b;
    int result = 0;

    for(int i = 0; i < 4; i++){
        if(temp & (1 << i)) result++;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int N;
        cin >> N;

        vector<int> exist(16, 0);

        string mbti;
        for(int i = 0; i < N; i++){
            int mask = 0;
            cin >> mbti;

            if(mbti[0] == 'I')
                mask |= (1 << 3);
            if(mbti[1] == 'S')
                mask |= (1 << 2);
            if(mbti[2] == 'T')
                mask |= (1 << 1);
            if(mbti[3] == 'J')
                mask |= (1 << 0);

            exist[mask]++;
        }

        int minDistance = 100;
        for(int A = 0; A < 16; A++){
            for(int B = 0; B < 16; B++){
                for(int C = 0; C < 16; C++){
                    vector<int> copied(exist);
                    int nowDistance = 0;

                    if(--copied[A] < 0) continue;
                    if(--copied[B] < 0) continue;
                    if(--copied[C] < 0) continue;

                    nowDistance += MindDistance(A, B);
                    nowDistance += MindDistance(B, C);
                    nowDistance += MindDistance(C, A);

                    if(minDistance > nowDistance) minDistance = nowDistance;
                }
            }
        }

        cout << minDistance << '\n';
    }

    return 0;
}
