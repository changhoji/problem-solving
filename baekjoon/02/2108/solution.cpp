#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Data {
    int number;
    int frequency;
};

bool comp(const Data &a, const Data &b){
    if(a.frequency == b.frequency)
        return a.number < b.number;
    return a.frequency > b.frequency;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N;
    cin >> N;
    
    vector<int> nums(N);

    int sum = 0;

    int num;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    // get mean
    double mean = (double)sum / N;
    mean = round(mean);

    // sort for getting other values
    sort(nums.begin(), nums.end());

    // get mode
    int curFrequency = 0;
    int curNumber = -4001;
    vector<Data> datas;
    Data data;

    for(auto i: nums){
        if(i != curNumber){
            // find different number
            if(curNumber != -4001){
                // push last number
                data.number = curNumber;
                data.frequency = curFrequency;
                datas.push_back(data);
            }
            // reset variables
            curNumber = i;
            curFrequency = 1;
        }
        else{
            curFrequency++;
        }
    }
    // push final number
    data.number = curNumber;
    data.frequency = curFrequency;
    datas.push_back(data);

    sort(datas.begin(), datas.end(), comp);

    int mode;

    // multiple modes
    if(datas.size() > 1 && datas[0].frequency == datas[1].frequency)
        mode = datas[1].number;
    else 
        mode = datas[0].number;

    cout << (int)mean << '\n';
    cout << nums[N/2] << '\n';
    cout << mode << '\n';
    cout << nums.back() - nums.front() << '\n';

    return 0;
}
