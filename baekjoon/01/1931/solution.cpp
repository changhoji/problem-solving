#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting{
    int start;
    int end;
};

bool comp(const Meeting &a, const Meeting &b){
    if(a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main(){
    int N;
    cin >> N;

    vector<Meeting> meetings;

    int s, e;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        meetings.push_back({s, e});
    }

    sort(meetings.begin(), meetings.end(), comp);

    int lastEnd = -1;
    int answer = 0;
    for(Meeting meeting: meetings){
        if(meeting.start < lastEnd) continue;
        lastEnd = meeting.end;
        answer++;
    }

    cout << answer << '\n';

    return 0;
}
