#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int GetPriority(char op){
    switch(op){
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '(':
            return 1;
        default:
            return -1;
    }
}

bool IsOperand(char c){
    return ('A' <= c && c <= 'Z');
}

int main(){
    string expression;
    cin >> expression;

    stack<char> s;

    string answer;
    for(char c: expression){
        if(IsOperand(c)){
            answer.push_back(c);
            continue;
        }

        char op;
        if(c == ')'){
            while(s.top() != '('){
                answer.push_back(s.top());
                s.pop();
            }
            s.pop();
        } else if(c == '('){
            s.push(c);
        } else{
            int priority = GetPriority(c);
            while(!s.empty() && GetPriority(s.top()) >= priority){
                answer.push_back(s.top());
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }

    cout << answer << '\n';

    return 0;
}
