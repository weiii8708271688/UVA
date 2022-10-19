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
vector <vector<int>> G;
int f, s, t, c;

void maxflow(int n) {
    while(true) {
        queue <int> q;
        q.push(s);
        int flow[n+1] = {0};
        flow[s] = INT_MAX;
        int p[n+1];
        for(int i = 0 ; i <= n ; i++) p[i] = -1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 1 ; v <= n ; v++) {
                if(!flow[v] && G[u][v] > 0) {
                    p[v] = u;
                    flow[v] = min(flow[u], G[u][v]);
                    q.push(v);
                }
            }
        }
        if(!flow[t]) break;
        for(int v = t ; v != s ;) {
            int u = p[v];
            G[u][v] -= flow[t];
            G[v][u] += flow[t];
            v = u;
        }
        f += flow[t];
    }
}


int main() {
    int n, time = 1;
    while(cin >> n) {
        if(!n) break;
        f = 0;
        G.assign(n+1, vector<int> (n+1));
        cin >> s >> t >> c;
        for(int i = 0 ; i < c ; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            G[a][b] += w;
            G[b][a] += w;
        }
        maxflow(n);
        cout << "Network " << time++ << endl;
        cout << "The bandwidth is " << f << "." << endl << endl;
    }
}
