#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <queue>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        priority_queue <int, vector<int>, greater<int>> q;
        while(n--) {
            int t;
            cin >> t;
            q.push(t);
        }
        int ans = 0;
        while(q.size() != 1) {
            int a, b;
            a = q.top();q.pop();
            b = q.top();q.pop();
            ans += a+b;
            q.push(a+b);
        }
        cout << ans << endl;
    }
}
