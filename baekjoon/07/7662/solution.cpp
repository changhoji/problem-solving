#include <iostream>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> pll;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(false);
    
    int T;
    cin >> T;

    int k, x;
    char cmd;
    
    for(int tc = 1; tc <= T; tc++){
        cin >> k;

        priority_queue<pll> maxHeap;
        priority_queue<pll, vector<pll>, greater<pll>> minHeap;
        int heapSize = 0;

        map<int, bool> deleted;

        for(int i = 0; i < k; i++){
            cin >> cmd >> x;

            if(cmd == 'I'){
                heapSize++;
                maxHeap.push(make_pair(x, i));
                minHeap.push(make_pair(x, i));
                deleted[i] = false;
            }
            else{
                if(heapSize == 0)
                    continue;

                if(x == 1){
                    pll cur = maxHeap.top();
                    while(deleted[cur.second]){
                        maxHeap.pop();
                        cur = maxHeap.top();
                    }
                    deleted[cur.second] = true;
                    maxHeap.pop();
                    heapSize--;
                }
                else{
                    pll cur = minHeap.top();
                    while(deleted[cur.second]){
                        minHeap.pop();
                        cur = minHeap.top();
                    }
                    deleted[cur.second] = true;
                    minHeap.pop();
                    heapSize--;
                }
            }
        }

        if(heapSize == 0) cout << "EMPTY\n";
        else{
            pll cur = minHeap.top();
            while(deleted[cur.second]){
                minHeap.pop();
                cur = minHeap.top();
            }

            cur = maxHeap.top();
            while(deleted[cur.second]){
                maxHeap.pop();
                cur = maxHeap.top();
            }

            cout << maxHeap.top().first << ' ' << minHeap.top().first << '\n';
        }
    }

    return 0;
}
