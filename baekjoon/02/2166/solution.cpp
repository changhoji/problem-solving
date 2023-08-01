#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

#define x first
#define y second

typedef long long ll;

typedef pair<ll, ll> Point;
typedef pair<ll, ll> Vector;

Vector operator-(const Point &a, const Point &b){
    return make_pair(b.x-a.x, b.y-a.y);
}

int CCW(const Point &a, const Point &b, const Point &c){
    Vector v1 = b - a;
    Vector v2 = c - b;

    int result = v1.x*v2.y - v1.y*v2.x;
    return (result > 0) - (result < 0);
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    int N;
    cin >> N;

    Point point[N];
    for(int i = 0; i < N; i++){
        cin >> point[i].x >> point[i].y;
    }

    double area = 0;
    for(int i = 0; i < N; i++){
        area += point[i].x*point[(i+1)%N].y;
        area -= point[i].x*point[(i+N-1)%N].y;
    }

    area = abs(area);
    area *= .5;

    printf("%.1lf\n", area);

    return 0;
}
