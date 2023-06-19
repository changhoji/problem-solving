#include <iostream>
#include <vector>
using namespace std;

struct {
    int index;
    int value;
} count;

int main(){
    string str;
    int used[26] = { 0,};
    char c;

    cin >> str;

    for(auto c: str){
        if(c <= 'Z')
            used[c-'A']++;
        else
            used[c-'a']++;
    }

    count.index = -1;
    count.value = 0;

    for(int i = 0; i < 26; i++){
        if(used[i] > count.value){ // when this letter's count is bigger than max
            count.index = i;
            count.value = used[i];
        }
        else if(used[i] == count.value) // panic when max count is duplicanted
            count.index = -1;
    }

    if(count.index == -1)
        cout << "?\n";
    else{
        c = 'A'+count.index;
        cout << c << '\n';
    }

    return 0;
}
