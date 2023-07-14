#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    string str;
    cin >> str;

    int answer = 0;
    int connect = -1;
    for(int i = 0; i < str.size()-1; i++){
        if(connect != -1){
            if(str[i] == 'O' && str[i+1] == 'I'){
                connect++;;
                i++;
            }
            else{
                answer += max(0, connect - N + 1);
                connect = -1;
            }
        }
        if(str[i] == 'I' && connect == -1) connect = 0;
    }
    answer += max(0, connect - N + 1);

    cout << answer << '\n';

    return 0;
}
