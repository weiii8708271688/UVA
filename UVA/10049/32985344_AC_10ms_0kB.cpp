#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
#include <map>
#include <ctime>
using namespace std;

int s[673367];

int f(int i, int r) {
    int l = 1;
    while(l <= r) {
        int m = (l+r)/2;
        if(s[m] == i) {
            return m;
        }
        if(s[m] >= i) {
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return l;
}


int main() {
    s[0] = 0;
    s[1] = 1;
    s[2] = 3;
    for(int i = 3 ; i < 673367 ; i++) {
        s[i] = s[i-1] + f(i, i-1);
        //cout << "s["<< i << "] == " << s[i] << endl;
    }
    int n;
    while(cin >> n) {
        if(!n) break;
        cout << lower_bound(s, s+673367, n)-s << endl;
    }
}
