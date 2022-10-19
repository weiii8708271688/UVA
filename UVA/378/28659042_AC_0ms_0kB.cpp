#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

struct vector_{
    double x;
    double y;
};


double slope(vector_ x1, vector_ x2) {
    return (x1.y-x2.y) / (x1.x - x2.x);
}

double ans(vector_ x1, double M) {
    return -1 * M * x1.x + x1.y;
}


int main(){
    vector_ x1,x2,x3,x4;
    int n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    cin >> n;
    while(n--) {
        cin >> x1.x >> x1.y >> x2.x >> x2.y >> x3.x >> x3.y >> x4.x >> x4.y;
        double slope1 = slope(x1,x2), slope2 = slope(x3,x4);
        double ans1 = ans(x1, slope1), ans2 = ans(x3, slope2);
        if(x1.x == x2.x && x3.x == x4.x) {
            ans1 = x1.x;
            ans2 = x3.x;
            if(x1.x == x3.x)
                cout << "LINE" << endl;
            else
                cout << "NONE" << endl;
        }else if(x1.x == x2.x) {
            ans1 = x1.x;
            ans2 += ans1*slope2;
            cout << "POINT " << fixed << setprecision(2) << ans1 << " " << ans2 << endl;
        }else if(x3.x == x4.x) {
            ans2 = x3.x;
            ans1 += ans2*slope1;
            cout << "POINT " << fixed << setprecision(2) << ans2 << " " << ans1 << endl;
        }
        if(x1.x == x2.x || x3.x == x4.x) continue;
        if(slope1 == slope2) {
            if(ans1 == ans2)
                cout << "LINE" << endl;
            else
                cout << "NONE" << endl;
        }else{
            ans1-=ans2;
            slope1 = -1*slope1 + slope2;
            ans1/=slope1;
            ans2 = ans2 + 1*slope2*ans1;
            cout << "POINT " << fixed << setprecision(2) << ans1 << " " << ans2 << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
}
