#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <queue>
using namespace std;

struct R_{
    int q, o, p;
};



class Compare {
public:
    bool operator() (R_ &a, R_ &b) {
    if(a.p == b.p) {
        return a.q > b.q;
    }
    return a.p > b.p;
}
};

int main() {
    string s;
    int tq, tp;
    priority_queue <R_, vector<R_>, Compare> R;
    while(cin >> s) {
        if(s == "#") break;
        cin >> tq >> tp;
        R_ temp;
        temp.q = tq;
        temp.p = temp.o = tp;
        R.push(temp);
    }
    int ans;
    cin >> ans;
    while(ans--) {
        R_ temp = R.top();
        R.pop();
        cout << temp.q << endl;
        temp.p += temp.o;
        R.push(temp);
    }
}
