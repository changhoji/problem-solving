#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define y first
#define x second

typedef long long ll;

typedef pair<ll, ll> Point;
typedef pair<ll, ll> Vector;

Vector operator-(const Point &a, const Point &b){
    Vector temp;
    temp.y = a.y-b.y;
    temp.x = a.x-b.x;
    return temp;
}

int CCW(const Point &a, const Point &b, const Point &c){
    Vector v1 = b - a;
    Vector v2 = c - b;

    ll result = v1.x*v2.y - v1.y*v2.x;

    return (result > 0) - (result < 0);
}

bool ConvexHull(const Point &prison, vector<Point> &pillars){
    for(int i = pillars.size()-1; i >= 1; --i){
        if(pillars[i] < pillars[i-1]) swap(pillars[i], pillars[i-1]);
    }

    Point base = pillars[0];
    sort(pillars.begin(), pillars.end(),
        [base](const Point &a, const Point &b){
            int ccw = CCW(base, a, b);
            if(ccw == 0) return (abs(a.x-base.x) + abs(a.y-base.y)) < (abs(b.x-base.x) + abs(b.y-base.y));
            return ccw == 1;
        });

    vector<int> v;

    for(int i = 0; i < pillars.size(); ++i){
        while(v.size() >= 2 && 
              CCW(pillars[v[v.size()-2]], pillars[v[v.size()-1]], pillars[i]) <= 0){
            v.pop_back();
        }
        v.push_back(i);
    }

    bool result = true;
    for(int i = 0; i < v.size(); ++i){
        int j = (i-1+v.size()) % v.size();
        if(CCW(pillars[v[j]], pillars[v[i]], prison) <= 0){
            result = false;
            break;
        }
    }

    for(int i = 0; i < v.size(); ++i){
        pillars.erase(pillars.begin()+v[i]-i);
    }

    return result;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    Point prison;
    cin >> N >> prison.x >> prison.y;

    vector<Point> pillars;
    Point p;
    for(int i = 0; i < N; ++i){
        cin >> p.x >> p.y;
        pillars.push_back(p);
    }

    int answer = 0;
    while(pillars.size() >= 3 && ConvexHull(prison, pillars) == true){
        answer++;
    }

    cout << answer << '\n';

    return 0;
}
