#include <iostream>
using namespace std;

int par[(int)1e6+1];

int Find(int a){
    if(par[a] == a) return a;
    else return par[a] = Find(par[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a != b){
        par[b] = a;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        par[i] = i;
    }

    int cmd, a, b;
    for(int i = 0; i < m; i++){
        cin >> cmd >> a >> b;

        if(cmd == 0){
            Union(a, b);
        } else{
            if(Find(a) == Find(b)){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}
