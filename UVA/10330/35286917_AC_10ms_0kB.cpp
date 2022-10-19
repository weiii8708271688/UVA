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
using namespace std;

vector <vector<int>> G;
int f, s, t;

void maxflow(int n) {
    while(true) {
        queue <int> q;
        q.push(s);
        int flow[n*2+2] = {0};
        flow[s] = INT_MAX;
        int p[n*2+2];
        for(int i = 0 ; i < t ; i++) p[i] = -1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 0 ; v < n*2+2 ; v++) {
                if(!flow[v] && G[u][v] > 0) {
                    p[v] = u;
                    flow[v] = min(flow[u], G[u][v]);
                    q.push(v);
                }
            }
        }
        if(!flow[t]) break;
        for(int v = t ; v != 0 ;) {
            int u = p[v];
            G[u][v] -= flow[t];
            G[v][u] += flow[t];
            v = u;
        }
        f += flow[t];
    }
}


int main() {
    int n, m, b, d;
    while(cin >> n) {
        s = 0;
        t = n*2+1;
        G.assign(n*2 + 2, vector<int>(n*2+2));
        for(int i = 1 ; i <= n ; i++) {
            cin >> G[i][i+n];
        }
        cin >> m;
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a+n][b] = c;
        }
        cin >> b >> d;
        while(b--) {
            int temp;
            cin >> temp;
            G[s][temp] = INT_MAX;
        }
        while(d--) {
            int temp;
            cin >> temp;
            G[temp+n][t] = INT_MAX;
        }
        f = 0;
        maxflow(n);
        cout << f << endl;
    }
}
