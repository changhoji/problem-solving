#include <iostream>
using namespace std;

int main(){
    int a[3];
    
    while(true){
        cin >> a[0] >> a[1] >> a[2];

        if(a[0] == 0) break;

        bool right = false;

        for(int i = 0; i < 3; i++){
            if(a[i]*a[i] + a[(i+1)%3]*a[(i+1)%3] == a[(i+2)%3]*a[(i+2)%3])
                right = true;
        }

        if(right)
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}
