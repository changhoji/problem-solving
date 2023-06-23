#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n, i;
    cin >> n;

    stack<int> s;
    vector<char> answer;
    int pushedMax = 0;

    for(i = 0; i < n; i++){
        int num;
        cin >> num;

        if(pushedMax > num && s.top() != num) break;
        while(pushedMax < num){
            s.push(++pushedMax);
            answer.push_back('+');
        }
        s.pop();
        answer.push_back('-');
    }

    if(i != n){
        cout << "NO\n";
    } else{
        for(char c: answer){
            cout << c << '\n';
        }
    }

    return 0;
}
