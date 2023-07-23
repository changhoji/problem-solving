#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>>  dist(n+1, vector<int>(n+1, INF));
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for(int mid = 1; mid <= n; mid++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ((dist[i][j] == INF) ? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
