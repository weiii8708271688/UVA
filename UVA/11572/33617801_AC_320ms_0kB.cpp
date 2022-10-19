#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;


int main() {
    int cas;
    cin >> cas;
    while(cas--) {
        int n;
        cin >> n;
        int snow[n];
        for(int i = 0 ;i < n ; i++) {
            cin >> snow[i];
        }
        set <int> package;
        int ans = 0, left = 0;
        for(int i = 0 ; i < n ; i++) {
            while(package.find(snow[i]) != package.end()) {
                package.erase(snow[left]);
                left++;
            }
            package.insert(snow[i]);
            int Size = package.size();
            ans = max(ans, Size);
        }
        cout << ans << endl;
    }
}
