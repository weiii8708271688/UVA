#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <vector>
using namespace std;

struct vertex{
    int d = 0, low = 0, p = -1, codenum = 0;
    vector <int> adj;
    bool arr = false;
};

vertex *v;
vector <pair <int, int> > ans;
int times;
vector <int> newadj[10002];

void dfs(int cur, bool* pass) {
    pass[cur] = true;
    v[cur].codenum = times;
    for(int i = 0 ; i < newadj[cur].size() ;i++) {
        int next = newadj[cur][i];
        if(!pass[next]) {
            dfs(next, pass);
        }
    }
}


void bridge(int cur, int pre) {
    v[cur].p = pre;
    v[cur].arr = true;
    times++;
    v[cur].d = v[cur].low = times;
    for(int i = 0 ; i < v[cur].adj.size() ; i++) {
        int next = v[cur].adj[i];
        if(!v[next].arr) {
            bridge(next, cur);
            v[cur].low = min(v[cur].low, v[next].low);
            if(v[next].low > v[cur].d) {
                if(next > cur) {
                    ans.push_back(make_pair(cur, next));
                }else{
                    ans.push_back(make_pair(next, cur));
                }
            }
        } else if(next != v[cur].p) {
            v[cur].low = min(v[cur].low, v[next].d);
        }
    }
    times++;
}

int main() {
    int R, C, Q;
    while(cin >> R >> C >> Q) {
        if(!R && !C && !Q) break;
        v = new vertex[R+1]();
        times = 0;
        ans.clear();
        for(int i = 0;  i < C ; i++) {
            char ch;
            int a, b;
            cin >> a >> b;
            v[a].adj.push_back(b);
            v[b].adj.push_back(a);
        }
        for(int i  = 1 ; i <= R ; i++) {
            if(!v[i].arr) {
                bridge(i, -1);
            }
            newadj[i].clear();
        }
        for(int i = 0 ; i < ans.size() ; i++) {
            newadj[ans[i].first].push_back(ans[i].second);
            newadj[ans[i].second].push_back(ans[i].first);
        }
        bool pass[R+1] = {0};
        times = 1;
        for(int i = 1 ; i <= R ; i++) {
            if(!pass[i]) {
                dfs(i, pass);
                times++;
            }
        }
        for(int i = 0 ; i < Q ; i++) {
            int a, b;
            bool Y = true;
            cin >> a >> b;
            if(!v[a].codenum || !v[b].codenum) Y = false;
            Y = (v[a].codenum == v[b].codenum? true: false);
            cout << (Y? "Y":"N") << endl;
        }
        cout << "-" << endl;
        delete []v;
    }
}
