#include <iostream>
using namespace std;

void PrintStars(int n){
    for(int i = 0; i < n; i++){
        putchar('*');
    }
    putchar('\n');
}

int main(){
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        PrintStars(i);
    }

    return 0;
}
