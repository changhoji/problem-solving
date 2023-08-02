#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

struct Point {
    int x;
    int y;

    Point() {}
    Point(int x, int y): x(x), y(y) {}
};

int CCW(const Point &p1, const Point &p2, const Point &p3){
    Point vec1 = Point(p2.x-p1.x, p2.y-p1.y);
    Point vec2 = Point(p3.x-p2.x, p3.y-p2.y);

    ll result = (ll)vec1.x*vec2.y - (ll)vec1.y*vec2.x;

    return (result > 0) - (result < 0);
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Point> point(N);
    for(int i = 0; i < N; i++){
        cin >> point[i].x >> point[i].y;
    }

    sort(point.begin(), point.end(),
        [](const Point &a, const Point &b){
            if(a.y == b.y) return a.x < b.x;
            return a.y < b.y;
        });
    Point base = point.front();

    // printf("base = (%d, %d)\n", base.x, base.y);

    sort(point.begin(), point.end(),
        [base](const Point &a, const Point &b){
            int ccw = CCW(base, a, b);
            // printf("a = (%d, %d), b = (%d, %d), ccw = %d\n", a.x, a.y, b.x, b.y, ccw);
            if(ccw == 0) return (abs(base.x-a.x)+abs(base.y-a.y)) < (abs(base.x-b.x)+abs(base.y-b.y));
            return ccw == 1;
        });
    
    for(auto p: point){
        // printf("(%d, %d)\n", p.x, p.y);
    }

    vector<Point> s;

    for(auto p: point){
        size_t size;
        while((size = s.size()) >= 2){
            if(CCW(s[size-2], s[size-1], p) <= 0) s.pop_back();
            else break;
        }
        s.push_back(p);
        // printf("p = (%d, %d), size = %d\n", p.x, p.y, s.size());
    }

    cout << s.size() << '\n';

    return 0;
}
