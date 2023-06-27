#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Member{
    int age;
    int timestamp;
    string name;
};

bool comp(const Member &a, const Member& b){
    if(a.age == b.age) return a.timestamp < b.timestamp;
    return a.age < b.age;
}

int main(){
    int N;
    cin >> N;

    vector<Member> members(N);

    for(int i = 0; i < N; i++){
        cin >> members[i].age >> members[i].name;
        members[i].timestamp = i;
    }

    sort(members.begin(), members.end(), comp);

    for(int i = 0; i < N; i++){
        cout << members[i].age << " " << members[i].name << '\n';
    }

    return 0;
}
