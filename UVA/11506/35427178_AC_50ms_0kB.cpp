#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;
vector <vector<int>> G, cap;
int f, s, t;


void maxflow(int n) {
    while(true) {
        int flow[n*2+2] = {0};
        int p[n*2+1] = {0};
        flow[s] = INT_MAX;
        queue <int> q;
        q.push(s);

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 1 ; v < n*2+1 ; v++) {
                if(!flow[v] && G[u][v] > 0) {
                    flow[v] = min(flow[u], G[u][v]);
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        if(!flow[t]) return;
        int mincap = INT_MAX;
        for(int v = t ; v != s ;) {
            int u = p[v];
            G[u][v] -= flow[t];
            G[v][u] += flow[t];
            mincap = min(mincap, cap[u][v]);
            //cout << "cap["<< u << "][" << v << "] == " << cap[u][v] << endl;
            //cout << "u :" << u << " v : " << v << endl;
            v = u;

        }
            //cout << "mincap : " << mincap << endl;

        f += flow[t];
    }
}


int main() {
    int m, w;
    while(cin >> m >> w) {
        if(!m && !w) break;
        G.assign(m*2+2, vector<int>(m*2+2));
        cap.assign(m*2+2, vector<int>(m*2+2));
        for(int i = 0 ; i < m-2 ; i++) {
            int a, cost;
            cin >> a >> cost;
            G[a][a+m] = cost;
            cap[a][a+m] = cost;
        }
        s = 1;
        t = m;
        G[s][s+m] = INT_MAX;
        cap[s][s+m] = INT_MAX;
        while(w--) {
            int a, b, cost;
            cin >> a >> b >> cost;
            G[a+m][b] = G[b+m][a] = cost;
            cap[a+m][b] = cap[b+m][a] = cost;
        }
        f = 0;
        maxflow(m);
        cout << f << endl;
    }
}
