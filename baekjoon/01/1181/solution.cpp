#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const string &a, const string &b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(){
    int N;
    cin >> N;

    vector<string> vec(N);

    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), cmp);
    
    string before = "";

    for(string str: vec){
        if(before != str)
            cout << str << '\n';
        before = str;
    }

    return 0;
}