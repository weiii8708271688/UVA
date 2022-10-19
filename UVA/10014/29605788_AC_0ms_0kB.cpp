#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;



int main() {
    int ca;
    cin >> ca;
    while(ca--) {
        int m;
        cin >> m;
        double A[2], C;
        cin >> A[0] >> A[1];
        double csum = 0;
        for(int i = 1 ; i <= m ; i++) {
            cin >> C;
            csum += C*(m-i+1);
        }
        double ans = (m*A[0] + A[1] - 2*csum) / (m+1);
        cout << fixed << setprecision(2) << ans << endl;
        if(ca) cout<< endl;
    }
}
