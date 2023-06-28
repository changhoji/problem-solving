#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N;
    cin >> N;

    int count[10001] = { 0,};
    
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        count[num]++;
    }

    for(int i = 1; i <= 10000; i++){
        if(count[i]){
            for(int j = 0; j < count[i]; j++) cout << i << '\n';
        }
    }

    return 0;
}
