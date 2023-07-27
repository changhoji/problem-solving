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

Tree TreeDP(int root, vector<vector<int>> &children){
    Tree now(0, 0);

    if(children[root].empty()){
        return now;
    }

    vector<int> heights;
    
    for(auto child: children[root]){
        Tree cur = TreeDP(child, children);

        now.height = max(now.height, cur.height);
        heights.push_back(cur.height+1);
    }
    now.height++;

    heights.push_back(0);
    sort(heights.begin(), heights.end(), greater<int>());

    now.diameter = now.height + heights[1];

    return now;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int n;
        cin >> n;

        vector<Tree> trees;

        int m, par, root;
        int diameter = 0;

        for(int i = 0; i < n; i++){
            cin >> m;

            vector<vector<int>> children(m+1);
            for(int j = 1; j <= m; j++){
                cin >> par;
                if(par == 0) root = j;
                children[par].push_back(j);
            }

            Tree now = TreeDP(root, children);
            printf("tree -> d: %d, h: %d\n", now.diameter, now.height);
            if(now.height == 0) continue;
            trees.push_back(now);
            diameter += now.height*2;
        }

        vector<int> result;
        for(auto t: trees){
            result.push_back(diameter - t.height*2 + t.diameter);
        }

        if(result.empty()){
            cout << "0 0\n";
        } else{
            cout << *max_element(result.begin(), result.end()) << ' ' << *min_element(result.begin(), result.end()) << '\n';
        }
    }

    return 0;
}
