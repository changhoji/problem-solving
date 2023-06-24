#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct PrinterJob {
    int index;
    int priority;
};

int main(){
    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++){
        int N, M;
        cin >> N >> M;

        int priorityCount[10] = { 0,};
        int existMask = 0;
        queue<PrinterJob> q;
        PrinterJob newJob;

        int num;
        for(int i = 0; i < N; i++){
            cin >> num;

            existMask |= (1 << num);

            newJob.index = i;
            newJob.priority = num;

            priorityCount[num]++;
            q.push(newJob);
        }

        int answer = 0;
        while(true){
            PrinterJob nowJob = q.front();
            if((1 << (nowJob.priority+1)) <= existMask){
                q.pop();
                q.push(nowJob);
            }
            else{
                answer++;
                q.pop();
                if (--priorityCount[nowJob.priority] == 0){
                    existMask &= ~(1 << nowJob.priority);
                }
                if(nowJob.index == M) break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
