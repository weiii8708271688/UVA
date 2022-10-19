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
vector < pair <int, int> > ans;
int times;


void bridge(int cur, int pre) {
    v[cur].p = pre;
    v[cur].arr = true;
    times++;
    v[cur].d = v[cur].low = times;
    for(int i = 0 ; i < v[cur].adj.size() ; i++) {
        int next = v[cur].adj[i];
        if(!v[next].arr) {
            v[cur].child++;
            bridge(next, cur);
            v[cur].low = min(v[cur].low, v[next].low);
            if(v[next].low > v[cur].d) {
                if(cur < next)
                    ans.push_back(make_pair(cur, next));
                else
                    ans.push_back(make_pair(next, cur));
            }
        } else if(next != v[cur].p) {
            v[cur].low = min(v[cur].low, v[next].d);
        }
    }
    times++;
}

int main() {
    int n, m, t = 1;
    while(cin >> n >> m) {
        if(!n && !m) break;
        ans.clear();
        v = new vertex[n]();
        times = 0;
        for(int i = 0 ; i < m ; i++) {
            int a, b;
            cin >> a >> b;
            v[a].adj.push_back(b);
            v[b].adj.push_back(a);
        }
        for(int i = 0 ; i < n ; i++) {
            if(!v[i].arr) {
                bridge(i, -1);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size();
        for(int i = 0 ; i < ans.size() ; i++) {
            cout << " " << ans[i].first << " " << ans[i].second;
        }
        cout << endl;
        delete []v;
    }
}
