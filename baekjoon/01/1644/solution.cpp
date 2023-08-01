#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int prime[4000001] = { 0,};

int main(){
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i <= 4000000; i += 2){
        if(prime[i] == 0){
            primes.push_back(i);
            for(int j = i; j <= 4000000; j += i){
                prime[j] = 1;
            }
        }
    }

    int N;
    cin >> N;

    int size = primes.size();
    int left = 0;
    int right = 0;

    ll sum = 2;
    int answer = 0;
    while(left < size && right < size){
        if(sum < N){
            sum += primes[++right];
        } else if(sum == N){
            answer++;
            sum -= primes[left++];
        } else{
            sum -= primes[left++];
        }
    }

    cout << answer << '\n';

    return 0;
}
