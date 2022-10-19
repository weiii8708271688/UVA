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

map <int, string> city;
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
    int n, m, t = 1;
    while(cin >> n) {
        if(!n) break;
        if(t != 1) cout << endl;
        v = new vertex[n+1]();
        times = 0;
        for(int i = 1 ; i <= n ; i++) {
            ans[i] = false;
            string s;
            cin >> s;
            city[i] = s;
        }
        cin >> m;
        while(m--) {
            string s1, s2;
            int a, b;
            cin >> s1 >> s2;
            for(int i = 1 ; i <= n ; i++) {
                if(city[i] == s1) a = i;
                if(city[i] == s2) b = i;
            }
            v[a].adj.push_back(b);
            v[b].adj.push_back(a);
        }
        for(int i  = 1 ; i <= n ; i++) {
            if(!v[i].arr) {
                cutpoint(i, -1);
            }
        }
        times = 1;
        vector <string> output;
        for(int i = 1 ; i <= n ;i++ ) {
            if(ans[i]) output.push_back(city[i]);
        }
        sort(output.begin(), output.end());
        cout << "City map #" << t++ << ": "<< output.size() << " camera(s) found" << endl;
        for(int i = 0 ; i < output.size() ; i++) {
            cout << output[i] << endl;
        }
        delete []v;
    }
}
