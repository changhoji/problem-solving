#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int N, K;
        cin >> N >> K;

        vector<int> time(N+1);
        for(int i = 1; i <= N; i++){
            cin >> time[i];
        }

        vector<vector<int>> next(N+1);
        vector<int> in(N+1, 0);

        int X, Y, W;
        for(int i = 0; i < K; i++){
            cin >> X >> Y;
            in[Y]++;
            next[X].push_back(Y);
        }

        queue<int> q;
        vector<int> taken(N+1, 0);

        for(int i = 1; i <= N; i++){
            if(in[i] == 0){
                taken[i] = time[i];
                q.push(i);
            }
        }

        cin >> W;

        while(in[W] >= 0){
            int size = q.size();

            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();

                for(int to: next[cur]){
                    in[to]--;
                    if(in[to] == 0) q.push(to);
                    taken[to] = max(taken[to], taken[cur] + time[to]);
                }
                in[cur]--;
            }
        }

        cout << taken[W] << '\n';
    }

    return 0;
}
