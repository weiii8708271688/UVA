#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

double ans, temp, x_;
double c[9], x[9];

double dis(double a, double b) {
    double A, B, C;
    C = a+b;
    B = abs(a-b);
    A = sqrt(C*C - B*B);
    return A;
}




int main() {
    int n, m;
    cin >> n;
    while(n--) {
        ans = 2147483646;
        cin >> m;
        for(int i = 0 ; i < m ; i++) {
            cin >> c[i];
        }
        sort(c, c+m);
        do{
            for(int i = 0 ; i < 9 ; i++) {
                x[i] = 0;
            }
            temp = c[0];
            x[0] = c[0];
            x_ = x[0];
            for(int i = 1 ; i < m ; i++) {
                x_ = c[i]; 
                for(int j = 0 ; j < i ; j++) {
                    double x2 = x[j] + dis(c[i], c[j]);
                    x_ = max(x_, x2);
                }
                x[i] = x_;
            }
            for(int i=0;i<m;i++) {
                temp=max(temp,x[i]+c[i]);
            }
            ans = min(ans, temp);
        }while(next_permutation(c, c+m));
        cout << fixed << setprecision(3) << ans << endl;
    }
}


