#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

bool cmp(int a, int b) {
    if(a > b) return true;
    return false;
}


int main() {
    int n;
    cin >> n;
    while(n--) {
        int cas;
        cin >> cas;
        int price[cas];
        for(int i = 0 ; i < cas ; i++) {
            cin >> price[i];
        }
        sort(price, price+cas, cmp);
        int ans = 0;
        if(cas >= 3) {
            for(int i = 2 ; i < cas ; i+=3) {
                ans+=price[i];
            }
        }
        cout << ans << endl;
    }
}
