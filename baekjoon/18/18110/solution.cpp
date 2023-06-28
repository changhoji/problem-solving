#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/// @brief 
/// @param opinion vector of submitted opinion of difficulty
/// @param exclusion number of people be excepted in one side
/// @return 
int CalculateDifficulty(const vector<int> &opinion){
    int sum = 0;
    
    if(opinion.empty()) return 0;
    
    int except = (int)round(round((double)opinion.size() * 0.3) / 2);

    for(int i = except; i < opinion.size()-except; i++){
        sum += opinion[i];
    }

    return (int)round((double)sum / (opinion.size()-2*except));
}

int main(){
    int n;
    cin >> n;

    vector<int> opinion(n);
    for(int i = 0; i < n; i++)
        cin >> opinion[i];

    sort(opinion.begin(), opinion.end());

    cout << CalculateDifficulty(opinion) << '\n';

    return 0;
}
