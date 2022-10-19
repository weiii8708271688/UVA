#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;


int main() {
    int d;
    while(cin >> d) {
        if(!d) break;
        multiset <long long> bill;
        long long ans = 0;
        while(d--) {
            int n;
            cin >> n;
            for(int i = 0 ; i < n ; i++) {
                long long temp;
                cin >> temp;
                bill.insert(temp);
            }
            ans += *bill.rbegin() - *bill.begin();
            bill.erase(bill.begin());
            bill.erase(--bill.end());
        }
        cout << ans << endl;
    }
}
