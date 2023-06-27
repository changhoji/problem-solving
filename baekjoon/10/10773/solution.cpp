#include <iostream>
#include <stack>
using namespace std;

int main(){
    int K;
    cin >> K;

    stack<int> s;

    int temp;
    for(int i = 0; i < K; i++){
        cin >> temp;
        if(temp == 0) s.pop();
        else s.push(temp);
    }

    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';

    return 0;
}
