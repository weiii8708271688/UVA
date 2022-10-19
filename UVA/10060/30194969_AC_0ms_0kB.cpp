#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#define Pi acos(-1)
using namespace std;

vector <double> x;
vector <double> y;

double cirvol(double r, double h) {
    return r*r*h*Pi;
}

double polyvol(double h) {
    double area = 0;
    for(int i = 0 ; i < x.size()-1 ; i++) {
        area += x[i]*y[i+1];
        area -= y[i]*x[i+1];
    }
    return abs(area*h/2);
}

void read() {
    x.clear();
    y.clear();
    double orix, oriy, tempx, tempy;
    cin >> orix >> oriy;
    x.push_back(orix);
    y.push_back(oriy);
    while(true) {
        cin >> tempx >> tempy;
        x.push_back(tempx);
        y.push_back(tempy);
        if(tempx == orix && tempy == oriy) return;
    }
}

int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        double sum = 0;
        while(n--) {
            double h;
            cin >> h;
            read();
            sum += polyvol(h);
        }
        double r, h;
        cin >> r >> h;
        double cir = cirvol(r,h);
        int ans = sum / cir;
        cout << ans << endl;
    }
}
