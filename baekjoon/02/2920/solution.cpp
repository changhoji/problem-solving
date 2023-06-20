#include <iostream>
using namespace std;

int main(){
    int num, before;
    cin >> before;

    bool ascending = true;
    bool descending = true;
    
    for(int i = 0; i < 7; i++){
        cin >> num;

        if(before < num)
            descending = false;
        else if(before > num)
            ascending = false;

        before = num;
    }

    if(ascending)
        cout << "ascending\n";
    else if(descending)
        cout << "descending\n";
    else
        cout << "mixed\n";

    return 0;
}
