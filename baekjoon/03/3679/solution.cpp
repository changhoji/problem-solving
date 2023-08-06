#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define y first
#define x second

typedef pair<int, int> Point;
typedef pair<int, int> Vector;

vector<Point> point(2000);

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

    int c;
    cin >> c;

    for(int tc = 1; tc <= c; tc++){
        int n;
        cin >> n;

        int X, Y;
        vector<int> order;
        for(int i = 0; i < n; i++){
            cin >> point[i].x >> point[i].y;
            order.push_back(i);
        }

        for(int i = n-1; i > 0; i--){
            if(point[order[i]] < point[order[i-1]]) swap(order[i-1], order[i]);
        }

        Point &base = point[0];

        sort(order.begin(), order.end(),
            [](int a, int b){
                int ccw = CCW(point[0], point[a], point[b]);
                if(ccw == 0) return (abs(point[a].x-point[0].x)+abs(point[a].y-point[0].y)) < (abs(point[b].x-point[0].x)+abs(point[b].y-point[0].y));
                return ccw == 1;
            });

        int back = n-1;
        vector<int> straight;
        straight.push_back(order[back]);
        while(back >= 2 && CCW(point[0], point[order[back]], point[order[back-1]]) == 0){
            back--;
            // printf("ccw[(%d, %d), (%d, %d), (%d, %d)] = %d\n", point[0].x, point[0].y, point[order[back+1]].x, point[order[back+1]].y, point[order[back]].x, point[order[back]].y, CCW(point[0], point[order[back+1]], point[order[back]]));
            straight.push_back(order[back]);
        }

        for(int i = 0; i < n-straight.size(); ++i){
            cout << order[i] << ' ';
        }
        for(auto iter = straight.begin(); iter != straight.end(); ++iter){
            cout << *iter << ' ';
        }
        cout << '\n';
    }

    return 0;
}
