#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

struct coor_{
    double x;
    double y;
};

double distence(coor_ a, coor_ b) {
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}

double min(double a, double b) {
    if(a > b) {
        return b;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        coor_ coor[m];
        bool check[m];
        for(int i = 0 ; i < m ; i++) {
            cin >> coor[i].x >> coor[i].y;
        }
        double dis[m][m];
        for(int i = 0 ; i < m ; i++) {
            check[i] = false;
            for(int j = 0 ; j < m ; j++) {
                dis[i][j] = distence(coor[i], coor[j]);
            }
        }
        double ans = 0;
        int a = 0, b = 0;
        double mini = 100000;
        check[0] = true;
        mini = 100000;
        while(true) {
            queue <int> q;
            for(int i = 0 ; i < m ; i++) {
                if(!check[i]) {
                    q.push(i);
                }
            }
            if(q.empty()) break;
            int Size = q.size();
            for(int i = 0 ; i < Size ; i++) {
                int cur = q.front();
                q.pop();
                for(int j = 0 ; j < m ; j++) {
                    if(!check[j] || cur == j) continue;
                    if(dis[cur][j] < mini) {
                        mini = dis[cur][j];
                        a = cur;
                        b = j;
                    }
                }
            }
            check[a] = true;
            check[b] = true;
            ans+=mini;
            mini = 100000;
        }
        cout << fixed << setprecision(2) << ans << endl;
        if(n)cout << endl;
    }
}
