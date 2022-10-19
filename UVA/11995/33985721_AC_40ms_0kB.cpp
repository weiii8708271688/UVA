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
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool a,b,c;
        a = b = c = true;
        while(n--) {
            int commed;
            cin >> commed;
            if(commed == 1) {
                int x;
                cin >> x;
                s.push(x);
                q.push(x);
                pq.push(x);
            }else{
                int ans;
                cin >> ans;
                if(s.empty()) {a = b = c = false; break;}
                if(s.top() != ans) a = false;
                if(q.front() != ans) b = false;
                if(pq.top() != ans) c = false;
                s.pop();
                q.pop();
                pq.pop();
            }
        }
        while(n > 0) {
            n--;
            int t,t2;
            cin >> t >> t2;
        }
        if(!a && !b && !c) cout << "impossible" << endl;
        else if(a && !b && !c) cout << "stack" << endl;
        else if(!a && b && !c) cout << "queue" << endl;
        else if(!a && !b && c) cout << "priority queue" << endl;
        else cout << "not sure" << endl;
    }
}
