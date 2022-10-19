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
    int n;
    while(cin >> n) {
        if(!n) break;
        queue <int> ans;
        int t;
        while(cin >> t) {
            if(!t) break;
            while(!ans.empty()) ans.pop();
            ans.push(t);
            for(int i = 1 ; i < n ; i++) {
                cin >> t;
                ans.push(t);
            }
            stack<int> s;
            for(int i = 1 ; i <= n ; i++) {
                s.push(i);
                while(s.top() == ans.front()) {
                    s.pop();
                    ans.pop();
                    if(ans.empty() || s.empty()) break;
                }
            }
            if(ans.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
}
