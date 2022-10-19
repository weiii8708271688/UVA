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
using namespace std;

struct vertex{
    int d = 0, low = 0, p = -1, child = 0;
    vector <int> adj;
    bool arr = false;
};

vertex *v;
bool ans[100000];
int times;
stack <int> s;
vector < set<int> > connect;


void cutpoint(int cur, int pre) {
    v[cur].p = pre;
    v[cur].arr = true;
    times++;
    s.push(cur);
    v[cur].d = v[cur].low = times;
    for(int i = 0 ; i < v[cur].adj.size() ; i++) {
        int next = v[cur].adj[i];
        if(!v[next].arr) {
            v[cur].child++;
            cutpoint(next, cur);
            v[cur].low = min(v[cur].low, v[next].low);
            if(v[next].low >= v[cur].d) {
                ans[cur] = true;
                set <int> temp;
                int t;
                do {
                    t = s.top();
                    temp.insert(t);
                    s.pop();

                }while(t != next && !s.empty());
                temp.insert(cur);
                connect.push_back(temp);
            }
        } else if(next != v[cur].p && v[next].d < v[cur].d) {
            v[cur].low = min(v[cur].low, v[next].d);
        }
    }
    //times++;
    if(v[cur].p == -1) {
        if(v[cur].child < 2) ans[cur] = false;
    }
}


int main() {
    int n, m, t = 1;
    while(cin >> n) {
        if(!n) break;
        connect.clear();
        v = new vertex[100000]();
        times = 0;
        int a, b, big = 0;
        while(n--) {
            cin >> a >> b;
            v[a].adj.push_back(b);
            v[b].adj.push_back(a);
            big = max(a, big);
            big = max(b, big);
        }

        for(int i = 1 ; i <= big ; i++) {
            ans[i] = false;
        }

        for(int i = 1 ; i <= big ; i++) {
            if(!v[i].arr) {
                cutpoint(i, -1);
            }
        }
        long long first = 0, second = 1;
        if (connect.size() == 1) first = 2, second = connect[0].size() * (connect[0].size() - 1) / 2;

        for(int i = 0 ; i < connect.size() ; i++) {
            int cutpointnum = 0;
            for(auto j: connect[i]) {
                if(ans[j]) cutpointnum++;
            }
            if(cutpointnum == 1) {
                first++;
                second *= (connect[i].size()-1);
            }
        }
        /*cout << "connect:" << endl;
        for(int i = 0 ; i < connect.size() ; i++) {
            for(int j = 0 ; j < connect[i].size() ; j++) {
                cout << connect[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << "Case " << t++ << ": ";
        cout << first << " " << second << endl;
        delete []v;
    }
}
