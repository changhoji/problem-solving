#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

int main(){
    pii point[3];
    for(int i = 0; i < 3; i++){
        cin >> point[i].x >> point[i].y;
    }

    pii vec1, vec2;
    vec1 = make_pair(point[1].x-point[0].x, point[1].y-point[0].y);
    vec2 = make_pair(point[2].x-point[1].x, point[2].y-point[1].y);

    int ccw = vec1.x*vec2.y - vec1.y*vec2.x;
    
    cout << (ccw > 0) - (ccw < 0) << '\n';

    return 0;
}
