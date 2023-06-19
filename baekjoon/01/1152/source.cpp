#include <iostream>
using namespace std;

int main(){
    string str;
    int cnt = 0;

    getline(cin, str);

    for(auto c: str){
        if(c == ' ')
            cnt++;
    }

    if(str.front() == ' ')
        cnt--;
    if(str.back() == ' ')
        cnt--;

    cout << cnt+1 << '\n';

    return 0;
}
