#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;

struct Point{
    double x, y;
};
vector <Point> point;

double dist(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


bool cmp1(Point a, Point b) {
    return a.x < b.x;
}

bool cmp2(Point a, Point b) {
    return a.y < b.y;
}

double closest_pair(int L, int R) {
    if(L >= R) return INT_MAX;
    int M = (L+R)/2;
    double dL = closest_pair(L, M);
    double dR = closest_pair(M+1, R);
    double d = min(dL, dR);
    vector <Point> temp;
    for(int i = L ; i <= M ; i++) {
        if(point[M].x - point[i].x < d) temp.push_back(point[i]);
    }
    for(int i = M+1 ; i <= R ; i++) {
        if(point[i].x - point[M].x < d) temp.push_back(point[i]);
    }
    sort(temp.begin(), temp.end(), cmp2);

    for(int i = 0 ; i < temp.size() ; i++) {
        for(int j = 1 ; i+j < temp.size() ; j++) {
            if(i+j < temp.size()) {
                d = min(d, dist(temp[i], temp[i+j]));
            }
        }
    }
    return d;
}
int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        point.assign(n, Point());
        for(int i = 0 ; i < n ; i++) {
            cin >> point[i].x >> point[i].y;
        }
        sort(point.begin(), point.end(), cmp1);
        double d = closest_pair(0, n-1);
        if(d > 10000) {
            cout << "INFINITY" << endl;
        }else{
            cout << fixed << setprecision(4) << d << endl;
        }
    }
}
