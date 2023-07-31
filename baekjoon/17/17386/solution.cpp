#include <iostream>
#include <utility>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll, ll> pll;

pll operator-(const pll &a, const pll &b){
    pll temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    return temp;
}

int CCW(pll p1, pll p2, pll p3){
    pll v1 = p2 - p1;
    pll v2 = p3 - p2;

    ll result = v1.x*v2.y - v1.y*v2.x;

    return (result > 0) - (result < 0);
}

int main(){
    pll p[4];

    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
    cin >> p[2].x >> p[2].y >> p[3].x >> p[3].y;

    int answer = 1;

    ll ccw[4];

    ccw[0] = CCW(p[0], p[1], p[2]);
    ccw[1] = CCW(p[0], p[1], p[3]);
    if(ccw[0] == ccw[1]) answer = 0;

    ccw[2] = CCW(p[2], p[3], p[0]);
    ccw[3] = CCW(p[2], p[3], p[1]);
    if(ccw[2] == ccw[3]) answer = 0;

    cout << answer << '\n';

    return 0;
}
