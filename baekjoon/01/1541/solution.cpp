#include <iostream>
#include <vector>
#include <string>
using namespace std;

void CalculateNext(const bool minusExist, int *answer, const int cur){
    if(minusExist)
        *answer -= cur;
    else
        *answer += cur;
}

int main(){
    string str;
    cin >> str;

    string temp;

    vector<int> num;
    vector<char> op;
    
    bool minusExist = false;
    int answer = 0;

    for(char c: str){
        if(c == '+'){
            CalculateNext(minusExist, &answer, stoi(temp));
            temp.clear();
        }
        else if(c == '-'){
            CalculateNext(minusExist, &answer, stoi(temp));
            temp.clear();
            minusExist = true;
        }
        else{
            temp.push_back(c);
        }
    }
    CalculateNext(minusExist, &answer, stoi(temp));
    
    cout << answer << '\n';

    return 0;
}
