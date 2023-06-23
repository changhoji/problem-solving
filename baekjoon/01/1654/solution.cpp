#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int PossiblePieces(vector<int> &cables, ll length){
    int result = 0;
    for(int cable: cables){
        result += cable / length;
    }
    return result;
}

int main(){
    int K, N;
    cin >> K >> N;

    vector<int> cables(K);
    for(int i = 0; i < K; i++)
        cin >> cables[i];
    
    ll left = 1;
    ll right = ~(1 << 31);
    int answer = 1;

    while(left <= right){
        ll mid = (left + right) / 2;
        int test = PossiblePieces(cables, mid);

        if(test < N){
            right = mid - 1;
        } else{
            if(answer < mid) answer = mid;
            left = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
