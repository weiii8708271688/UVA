#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

struct point_{
    double x,y;
};

point_ point[100];

double dis(point_ a, point_ b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

point_ outcenter(point_ a, point_ b, point_ c) {
    point_ temp;
    double A1 = a.x-b.x, B1 = a.y - b.y, C1 = (a.x*a.x - b.x*b.x + a.y*a.y - b.y*b.y)/2;
    double A2 = a.x-c.x, B2 = a.y - c.y, C2 = (a.x*a.x - c.x*c.x + a.y*a.y - c.y*c.y)/2;
    temp.x = (C1*B2-C2*B1) / (A1*B2-A2*B1);
    temp.y = (C1*A2-C2*A1) / (B1*A2-B2*A1);
    return temp;
}




int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        double R;
        for(int i = 0 ; i < n ; i++) {
            cin >> point[i].x >> point[i].y;
        }
        cin >> R;
        point_ c = point[0];
        double r = 0;
        for(int i = 1 ; i < n ; i++) {
            if(dis(c, point[i]) > r) {
                r = 0;
                c = point[i];
                for(int j = 0 ; j < i ; j++) {
                    if(dis(c, point[j]) > r) {
                        c.x = (point[i].x + point[j].x)/2;
                        c.y = (point[i].y + point[j].y)/2;
                        r = dis(c, point[j]);
                        for(int k = 0 ; k < j ; k++) {
                            if(dis(c, point[k]) > r) {
                                c = outcenter(point[i], point[j], point[k]);
                                r = dis(c, point[i]);
                            }
                        }
                    }
                }
            }
        }
        if(r <= R) {
            cout << "The polygon can be packed in the circle." << endl;
        }else{
            cout << "There is no way of packing that polygon." << endl;
        }
    }
}


