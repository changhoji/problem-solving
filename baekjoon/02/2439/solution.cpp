#include <iostream>
using namespace std;

void PrintCharacters(char ch, int n){
    for(int i = 0; i < n; i++){
        putchar(ch);
    }
}

int main(){
    int N;
    
    cin >> N;

    for(int i = 1; i <= N; i++){
        PrintCharacters(' ', N-i);
        PrintCharacters('*', i);
        putchar('\n');
    }

    return 0;
}
