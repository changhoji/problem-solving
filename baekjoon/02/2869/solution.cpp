#include <iostream>
using namespace std;

int main(){
    int A, B, V;
    cin >> A >> B >> V;

    int remainder = (V - A) % (A - B);
    
    int answer = (V - A) / (A - B) + 1;

    if(remainder != 0)
        answer++;   
    
    cout << answer << '\n';

    return 0;
}
