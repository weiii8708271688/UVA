#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Point{
    int x, y;
};

vector <Point> point;

int dist(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool cmp(Point a, Point b) {
    return a.x < b.x;
}

bool cmp2(Point a, Point b) {
    return a.y < b.y;
}

int closest_pair(int L, int R) {
    if(L >= R) return INT_MAX;
    int M = (L+R)/2;
    int dL = closest_pair(L, M);
    int dR = closest_pair(M+1, R);
    int d = min(dL, dR);
    vector <Point> temp;
    for(int i = L ; i <= M ; i++) {
        if(point[M].x - point[i].x < d) temp.push_back(point[i]);
    }
    for(int i = M+1 ; i <= R ; i++) {
        if(point[i].x - point[M].x < d) temp.push_back(point[i]);
    }
    sort(temp.begin(), temp.end(), cmp2);
    for(int i = 0 ; i < temp.size() ; i++) {
        for(int j = 1 ; j < 4 ; j++) {
            if(i+j < temp.size()) {
                d = min(d, max(abs(temp[i].x - temp[i+j].x), abs(temp[i].y - temp[i+j].y)));
            }
        }
    }
    return d;
}




int main() {
    int n;
    while(cin >> n) {
        point.assign(n, Point());
        for(int i = 0 ; i < n ; i++) {
            cin >> point[i].x >> point[i].y;
        }
        sort(point.begin(), point.end(), cmp);
        int d = closest_pair(0, n-1);
        cout << d << endl;
    }
}
