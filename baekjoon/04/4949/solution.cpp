#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str;
    
    while(true){
        getline(cin, str);
        if(str == ".") break;

        stack<char> s;
        string answer = "yes";
        for(char c: str){
            if(c == '(' || c == '{' || c == '[') s.push(c);
            
            char top;
            if(c == ')' || c == '}' || c == ']'){
                if(s.empty()) {
                    answer = "no";
                    break;
                }
                top = s.top();
                s.pop();
            }

            if(c == ')' && top != '('){
                answer = "no";
                break;
            }
            if(c == '}' && top != '{'){
                answer = "no";
                break;
            }
            if(c == ']' && top != '['){
                answer = "no";
                break;
            }
        }
        if(!s.empty()) answer = "no";

        cout << answer << '\n';
    }

    return 0;
}
