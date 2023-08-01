#include <iostream>
#include <utility>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll, ll> Point;
typedef pair<ll, ll> Vector;

int CCW(const Point &a, const Point &b, const Point &c){
    Vector v1 = {b.x-a.x, b.y-a.y};
    Vector v2 = {c.x-b.x, c.y-b.y};

    ll result = v1.x*v2.y - v1.y*v2.x;

    return (result > 0) - (result < 0);
}

int main(){
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    int ccw123 = CCW(p1, p2, p3);
    int ccw124 = CCW(p1, p2, p4);
    int ccw341 = CCW(p3, p4, p1);
    int ccw342 = CCW(p3, p4, p2);

    int answer = 1;
    if(ccw123 == 0 && ccw124 == 0){ // 4 points are on one line
        if(p1 > p2) swap(p1, p2);
        if(p3 > p4) swap(p3, p4);
        answer = (p2 >= p3 && p4 >= p1);
    } else{
        answer = (ccw123*ccw124 <= 0 && ccw341*ccw342 <= 0);
    }

    cout << answer << '\n';

    return 0;
}
