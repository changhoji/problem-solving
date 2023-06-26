#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int five, three;

    for(five = N/5; five >= 0; five--){
        int rest = N - 5 * five;
        if(rest % 3 == 0){
            three = rest / 3;
            break;
        }
    }

    if(five >= 0)
        cout << five+three << '\n';
    else
        cout << "-1\n";

    return 0;
}
