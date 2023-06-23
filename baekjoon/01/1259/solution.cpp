#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string str, temp;

    while(true){
        cin >> str;

        if(str == "0") break;

        temp = str;

        reverse(str.begin(), str.end());

        if(str == temp)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
