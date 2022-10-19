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
    int d = 0, low = 0, p = -1;
    vector <int> adj;
    bool arr = false;
};

vertex *v;
vector <pair <int, int> > ans;
int times;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
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
    int n;
    while(cin >> n) {
        v = new vertex[n]();
        times = 0;
        ans.clear();
        for(int i = 0;  i < n ; i++) {
            char ch;
            int a, b, num;
            cin >> a >> ch >> num >> ch;
            while(num--) {
                cin >> b;
                v[a].adj.push_back(b);
            }
        }
        for(int i  = 0 ; i < n ; i++) {
            if(!v[i].arr) {
                bridge(i, -1);
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << ans.size() << " critical links" << endl;
        for(int i = 0 ; i < ans.size() ; i++) {
            cout << ans[i].first << " - " << ans[i].second << endl;
        }
        cout << endl;
        delete []v;
    }
}
