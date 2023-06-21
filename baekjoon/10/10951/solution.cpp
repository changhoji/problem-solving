#include <iostream>
using namespace std;

int main(){
    int A, B;
    
    while(true){
        if(!(cin >> A)) break;
        cin>> B;

        cout << A+B << '\n';
    }

    return 0;
}
