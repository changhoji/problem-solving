#include <iostream>
#include <string>
using namespace std;

int N;
string answer;

string sequence;

bool IsGoodSequence(){
    int right = sequence.size()-1;
    int left = sequence.size()-2;

    int len = 1;
    while(left >= 0){
        if(sequence.substr(left, len) == sequence.substr(right, len)){
            return false;
        } 
        right -= 1;
        left -= 2;
        len++;
    }

    return true;
}

void GoodSequence(int index){
    if(answer.length()) return;

    if(index == N){
        answer = sequence;
        return;
    }

    for(int next = 1; next <= 3; next++){
        sequence.push_back(next+'0');
        if(IsGoodSequence()){
            GoodSequence(index+1);
        }
        sequence.pop_back();
    }
}

int main(){
    cin >> N;

    GoodSequence(0);

    cout << answer << '\n';

    return 0;
}
