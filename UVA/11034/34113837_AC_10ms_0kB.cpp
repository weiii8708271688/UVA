#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;


int main() {
    int c;
    cin >> c;
    while(c--) {
        int l, m;
        cin >> l >> m;
        queue <int> right, left;
        bool inleft = true;
        while(m--) {
            int len;
            string s;
            cin >> len >> s;
            if(s == "right") right.push(len);
            else left.push(len);
        }
        int ans = 0;
        while(true) {
            if(right.empty() && left.empty()) break;
            queue <int> &cur = (inleft? left: right);
            inleft = !inleft;
            double remain = l;
            while(!cur.empty()) {
                if(remain - (double)cur.front()/100 >= 0) {
                    remain -= (double)cur.front()/100;
                    cur.pop();
                }else break;
            }
            ans++;
        }
        cout << ans << endl;
    }
}
