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
        int n,s,q;
        cin >> n >> s >> q;
        queue <int> qe[n+1];
        for(int i = 1 ; i <= n ; i++) {
            int qi;
            cin >> qi;
            while(qi--) {
                int t;
                cin >> t;
                qe[i].push(t);
            }
        }
        int ans = 0, pos = 1;
        stack <int> car;
        while(true) {
            while(!car.empty() && (car.top() == pos||qe[pos].size() < q) ) {
                if(car.top() != pos) {
                    qe[pos].push(car.top());
                }
                car.pop();
                ans++;
            }


            while(car.size() < s) {
                if(qe[pos].empty()) break;
                car.push(qe[pos].front());
                qe[pos].pop();
                ans++;
            }


            bool b = true;
            for(int i = 1 ; i <= n ; i++) {
                if(!qe[i].empty()) {
                    b = false;
                    break;
                }
            }
            if(b && car.empty()) break;
            ans+=2;
            pos %= n;
            pos++;
        }

        cout << ans << endl;

    }
}
