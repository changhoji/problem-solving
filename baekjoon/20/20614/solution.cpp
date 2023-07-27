#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tree {
    int diameter;
    int height;

    Tree() {}
    Tree(int diameter, int height): diameter(diameter), height(height) {}
};

vector<int> result;
vector<int> children[100001];
vector<Tree> trees;

Tree TreeDP(int root){
    Tree now(0, 0);

    if(children[root].empty()){
        return now;
    }

    vector<int> heights;
    int maxDiameter = 0;
    
    for(auto child: children[root]){
        Tree cur = TreeDP(child);

        now.height = max(now.height, cur.height);
        maxDiameter = max(maxDiameter, cur.diameter);
        heights.push_back(cur.height+1);
    }
    now.height++;

    heights.push_back(0);
    sort(heights.begin(), heights.end(), greater<int>());

    now.diameter = max(now.height + heights[1], maxDiameter);

    return now;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int n;
        cin >> n;

        result.clear();
        trees.clear();

        int m, par, root;
        int diameter = 0;

        for(int i = 0; i < n; i++){
            cin >> m;

            for(int j = 1; j <= m; j++){
                children[j].clear();
            }
            for(int j = 1; j <= m; j++){
                cin >> par;
                if(par == 0) root = j;
                else children[par].push_back(j);
            }
            Tree now = TreeDP(root);
            if(now.height == 0) continue;
            trees.push_back(now);
            diameter += now.height*2;
        }

        result.clear();
        for(auto t: trees){
            result.push_back(diameter - t.height*2 + t.diameter);
        }

        if(result.empty())
            result.push_back(0);

        sort(result.begin(), result.end());

        cout << result.back() << ' ' << result.front() << '\n';
    }

    return 0;
}
