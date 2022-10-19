#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int k, a, remain;
        cin >> k;
        k = abs(k);
        if(k == 0) {
            cout << 3 << endl;
            if(n) cout << endl;
            continue;
        }
        a = sqrt(2*k);
        while((a*a + a)/2 < k) {
            a++;
        }
        remain = (a*a + a)/2 - k;
        if(remain == 0 || remain % 2 == 0) {
            cout << a << endl;
        }else{
            if( (remain + a + 1) % 2 == 0) {
                cout << a+1 << endl;
            }else{
                cout << a+2 << endl;
            }
        }

        if(n) cout << endl;
    }
}


