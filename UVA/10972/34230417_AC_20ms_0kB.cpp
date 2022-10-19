#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

struct vertex{
    int d = 0, low = 0, p = -1, child = 0;
    vector <int> adj;
    bool arr = false;
};

vertex *v;
int times;
vector <int> bridge;

void dfs(int cur, int pre) {
    v[cur].p = pre;
    v[cur].arr = true;
    times++;
    v[cur].d = v[cur].low = times;
    for(int i = 0 ; i < v[cur].adj.size() ; i++) {
        int next = v[cur].adj[i];
        if(!v[next].arr) {
            v[cur].child++;
            dfs(next, cur);
            v[cur].low = min(v[cur].low, v[next].low);
            if(v[next].low > v[cur].d) {
                bridge.push_back(cur);
                bridge.push_back(next);
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
        v = new vertex[1001]();
        times = 0;
        bridge.clear();
        int a, b, num = 1;
        while(m--) {
            cin >> a >> b;
            v[a].adj.push_back(b);
            v[b].adj.push_back(a);
        }
        int con0 = 0, con1 = 0;
        for(int i = 1 ; i <= n ; i++) {
            if(!v[i].arr) {
                int temp = bridge.size();
                dfs(i, -1);
                if(temp == bridge.size()) con0++;
            }
        }

        if(bridge.empty() && con0 == 1) cout << "0" << endl;
        else{
            map <int, int> de;
            for (int i = 1; i <= n; i++)
            {
                de[v[i].low] += 0;
                if(v[i].adj.empty()) continue;
                for(auto next: v[i].adj) {
                    if(v[next].low != v[i].low && v[i].low >= 0) de[v[i].low]++;
                }
            }
            for(auto& d :de) {
                if(d.second == 1) con1++;//, cout << "de.first" << d.first << endl;
            }
            //cout << "con0: " << con0 << " " << " con1: " << con1 << endl;
            cout << con0 + (con1+1)/2 << endl;
        }


        delete []v;
    }
}
