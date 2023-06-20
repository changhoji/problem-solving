#include <iostream>
using namespace std;

int main(){
    int num, index, maxValue; 

    index = -1;
    maxValue = -1;

    for(int i = 1; i <= 9; i++){
        cin >> num;
        if(maxValue < num){
            index = i;
            maxValue = num;
        }
    }

    cout << maxValue << '\n' << index << '\n';

    return 0;
}
