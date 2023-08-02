#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define y first
#define x second

typedef pair<int, int> Point;
typedef pair<int, int> Vector;

Vector operator-(const Point &a, const Point &b){
    return {a.y-b.y, a.x-b.x};
}

int CCW(const Point &a, const Point &b, const Point &c){
    Vector v1 = b - a;
    Vector v2 = c - b;

    int result = v1.x*v2.y-v1.y*v2.x;

    return (result > 0) - (result < 0);
}

bool operator<(const Point &a, const Point &b){
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int P;
    cin >> P;

    for(int tc = 1; tc <= P; tc++){
        int N;
        cin >> N;

        vector<Point> point;
        int X, Y;
        for(int i = 0; i < N; i++){
            cin >> X >> Y;
            point.push_back({Y, X});
        }

        for(int i = N-1; i > 0; i--){
            if(point[i] < point[i-1]) swap(point[i], point[i-1]);
        }

        Point &base = point[0];

        sort(point.begin(), point.end(),
            [base](const Point &a, const Point &b){
                int ccw = CCW(base, a, b);
                if(ccw == 0) return (abs(a.x-base.x)+abs(a.y-base.y)) < (abs(b.x-base.x)+abs(b.y-base.y));
                return ccw == -1;
            });

        vector<Point> v;
        for(int i = 0; i < N; i++){
            Point now = point[i];
            while(v.size() >= 2 && CCW(v[v.size()-2], v[v.size()-1], now) >= 0){
                v.pop_back();
            }
            v.push_back(now);
        }

        cout << v.size() << '\n';
        for(auto p: v){
            cout << p.x << ' ' << p.y << '\n';
        }
    }

    return 0;
}