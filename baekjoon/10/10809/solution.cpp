#include <iostream>
using namespace std;

int main(){
    string word;
    int pos[26];
    
    for(int i = 0; i < 26; i++)
        pos[i] = -1;

    cin >> word;

    for(int i = 0; i < word.size(); i++){
        int index = word[i] - 'a';
        if(pos[index] == -1) pos[index] = i;
    }

    for(int i = 0; i < 26; i++)
        cout << pos[i] << " ";
    cout << '\n';

    return 0;
}
