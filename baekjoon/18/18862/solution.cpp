#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define NMAX 316402

typedef long long ll;
typedef pair<int, int> pii;

ll H[NMAX+1];
int children[NMAX+1] = { 0,};
vector<int> adj[NMAX+1];
vector<int> dp[NMAX+1];
vector<stack<int>> stacks;
vector<int> before;

template <typename T>
void PrintVec(const vector<T> &vec, const string str){
    cout << str << ": ";
    for(T n: vec){
        cout << n << ' ';
    }
    cout << '\n';
}

void CountChildren(int root, int parent){
    for(auto child: adj[root]){
        if(child == parent) continue;
        children[root]++;
        CountChildren(child, root);
    }
}

void TreeDP(int root, int parent, int depth, vector<int> before){
    dp[root].resize(depth+1);
    for(int i = 0; i < depth; i++){
        if(before[i] == -1 || before[i] < H[root]){
            before[i] = -1;
            dp[root][i] = 0;
        }
        else{
            before[i] = H[root] + (before[i] - H[root]) / 2;
            dp[root][i] = 1;
        }
    }
    before.push_back(H[root]);
    dp[root][depth] = 1;

    // cout << "before: ";
    // for(int i = 0; i <= depth; i++){
    //     cout << before[i] << ' ';
    // }
    // cout << '\n'; 

    for(auto child: adj[root]){
        if(child == parent) continue;

        TreeDP(child, root, depth+1, before);

        for(int j = 0; j <= depth; j++){
            dp[root][j] += dp[child][j];
        }
    }
    // PrintVec(dp[root], "dp");
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;

    cin >> N;
    H[0] = 1'000'000'000'000'000;
    for(int i = 1; i <= N; i++){
        cin >> H[i];
    }

    int u, v;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    TreeDP(1, 0, 0, vector<int>());

    for(int i = 1; i <= N; i++){
        cout << dp[i].back() << ' ';
    }
    cout << '\n';

    return 0;
}
