#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <vector>
#include <sstream>
using namespace std;

struct vertex{
    int d = 0, low = 0, p = -1, child = 0;
    vector <int> adj;
    bool arr = false;
};

vertex *v;
bool ans[101];
int times;


void cutpoint(int cur, int pre) {
    v[cur].p = pre;
    v[cur].arr = true;
    times++;
    v[cur].d = v[cur].low = times;
    for(int i = 0 ; i < v[cur].adj.size() ; i++) {
        int next = v[cur].adj[i];
        if(!v[next].arr) {
            v[cur].child++;
            cutpoint(next, cur);
            v[cur].low = min(v[cur].low, v[next].low);
            if(v[next].low >= v[cur].d && v[cur].p != -1) {
                ans[cur] = true;
            }
        } else if(next != v[cur].p) {
            v[cur].low = min(v[cur].low, v[next].d);
        }
    }
    if(v[cur].p == -1) {
        if(v[cur].child > 1) {
            ans[cur] = true;
        }
    }
    times++;
}

int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        v = new vertex[n+1]();
        times = 0;
        int m;
        string s;
        getline(cin, s);
        while(getline(cin, s)) {
            stringstream s1;
            s1 << s;
            int a, b;
            s1 >> a;
            if(!a) break;
            while(true) {
                s1 >> b;
                if(s1.fail()) break;
                v[a].adj.push_back(b);
                v[b].adj.push_back(a);
            }
        }
        for(int i = 1 ; i <= n ; i++) {
            ans[i] = false;
        }
        for(int i  = 1 ; i <= n ; i++) {
            if(!v[i].arr) {
                cutpoint(i, -1);
            }
        }
        times = 1;
        int output = 0;
        //cout << "cut point: ";
        for(int i = 1 ; i <= n ; i++) {
            if(ans[i]) {
                output++;
                //cout << i << " ";
            }
        }
        //cout << endl;
        cout << output << endl;
        delete []v;
    }
}
