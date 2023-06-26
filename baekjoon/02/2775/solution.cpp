#include <iostream>
using namespace std;

void FillApartment(int (*people)[15]){
    for(int i = 1; i <= 14; i++){
        people[0][i] = i;
    }

    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            // for each [n][k] room
            for(int k = 1; k <= j; k++){
                people[i][j] += people[i-1][k];
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    int people[15][15] = { 0,};
    FillApartment(people);

    for(int tc = 0; tc < T; tc++){
        int k, n;
        cin >> k >> n;

        cout << people[k][n] << '\n';
    }

    return 0;
}
