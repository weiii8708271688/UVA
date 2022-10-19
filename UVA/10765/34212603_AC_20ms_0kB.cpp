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
    int d = 0, low = 0, p = -1, child = 0, goose = 1, codenum;
    vector <int> adj;
    bool arr = false;
};

vertex *v;
bool ans[10002];
int times;

bool cmp(vertex a, vertex b) {
    if(a.goose == b.goose) {
        return a.codenum < b.codenum;
    }
    return a.goose > b.goose;
}



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
            if(v[next].low >= v[cur].d && v[cur].p != -1 ) {
                ans[cur] = true;
                v[cur].goose++;
            }
        } else if(next != v[cur].p) {
            v[cur].low = min(v[cur].low, v[next].d);
        }
    }
    times++;
    if(v[cur].p == -1) {
        if(v[cur].child > 1) ans[cur] = true;
    }
}



void dfs(bool* pass, int cur) {
    pass[cur] = true;
    for(int i  = 0 ; i < v[cur].adj.size() ; i++) {
        int next = v[cur].adj[i];
        if(next == 0) continue;
        if(!pass[next]) {
            dfs(pass, next);
        }
    }
}

int main() {
    int n, m, t = 1;
    while(cin >> n >> m) {
        if(!n && !m) break;
        v = new vertex[n]();
        times = 0;
        int a, b;
        for(int i = 0 ; i < n ; i++) {
            ans[i] = false;
            v[i].codenum = i;
        }
        while(cin >> a >> b) {
            if(a == -1 && b == -1) break;
            v[a].adj.push_back(b);
            v[b].adj.push_back(a);
        }
        for(int i = 0 ; i < n ; i++) {
            if(!v[i].arr) {
                cutpoint(i, -1);
            }
        }
        if(ans[0]) {
            v[0].goose = 0;
            bool pass[n] = {0};
            for(int i = 1 ; i < n ; i++) {
                if(!pass[i]) {
                    dfs(pass, i);
                    v[0].goose++;
                }
            }
        }
        sort(v, v+n, cmp);
        for(int i = 0 ; i < m ; i++) {
            cout << v[i].codenum << " " << v[i].goose << endl;
        }
        cout << endl;
        delete []v;
    }
}
