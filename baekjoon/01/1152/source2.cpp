#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string str;
    int cnt = 0;

    getline(cin, str);

    stringstream stream;
    stream.str(str);

    while(stream >> str)
        cnt++;

    cout << cnt << '\n';

    return 0;
}
