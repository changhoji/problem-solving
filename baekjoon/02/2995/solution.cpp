#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

struct Interval {
    int start;
    int end;
};

bool comp(const Interval a, const Interval b){
    if(a.end == b.end) return a.start < b.start;
    return b.end < a.end;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Interval> intervals(N+1);
    for(int i = 1; i <= N; i++){
        cin >> intervals[i].start >> intervals[i].end;
    }
    sort(intervals.begin()+1, intervals.end(), comp);

    vector<int> minLast(N+2, INF);
    vector<int> location(N+1);

    int len = 0;
    for(int i = 1; i <= N; i++){
        int index = upper_bound(minLast.begin()+1, minLast.end(), intervals[i].start) - minLast.begin();

        location[i] = index;
        minLast[index] = intervals[i].start;
        len = max(len, index);
    }

    cout << len << '\n';

    vector<Interval> answer;

    for(int i = intervals.size()-1; i >= 1; i--){
        if(location[i] == len){
            answer.push_back(intervals[i]);
            len--;
        }
    }

    for(auto iter = answer.rbegin(); iter != answer.rend(); iter++){
        cout << iter->start << ' ' << iter->end << '\n';
    }

    return 0;
}
