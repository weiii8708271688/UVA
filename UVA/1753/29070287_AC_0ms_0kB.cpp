#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

double max(double a, double b) {
    if(a > b) return a;
    return b;
}


int main(){
    int num, T;
    int i, j, k;
    while(cin >> num >> T) {
        double mx = 1e9, mn = -1e9;
        double d[num], s[num];
        for(k = 0 ; k < num ; k++){
            cin >> i >> j;
            d[k] = i;
            s[k] = j;
            mn = max(mn, -j);
        }
        while(mx-mn > 1e-9) {
            double c = (mx+mn)/2, t = 0;
            for(i = 0 ; i < num ; i++) {
                t += d[i]/(s[i]+c);
            }
            if(T > t) {
                mx = c;
            }else{
                mn = c;
            }
        }
        cout << fixed << setprecision(9) << (mx+mn)/2 << endl;
    }
}
