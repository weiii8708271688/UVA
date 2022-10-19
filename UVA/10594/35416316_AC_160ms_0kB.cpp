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
vector <vector<long long>> cap, Cost, adjlist, flow;
long long f, s, t;
vector <long long> p, cost;



void SPFA(int n) {
    p.assign(n+2, 0);
    cost.assign(n+2, INT_MAX);
    cost[s] = 0;
    queue <int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adjlist[u]) {
            if(cost[u] - Cost[v][u] < cost[v] && flow[v][u] > 0) {
                cost[v] = cost[u] - Cost[v][u];
                p[v] = u;
                q.push(v);
            }
            if(cost[u] + Cost[u][v] < cost[v] && cap[u][v] > flow[u][v]) {
                cost[v] = cost[u] + Cost[u][v];
                p[v] = u;
                q.push(v);
            }
        }
    }
    for(int i = 0 ; i <= n+1 ; i++) {
        //cout << "cost[" << i << "] == " << cost[i] <<endl;
    }
}

void maxflow(int n) {
    while(true) {
        SPFA(n);
        long long minflow = INT_MAX;
        if(cost[t] == INT_MAX) return;
        for(int v = t ; v != s;) {
            int u = p[v];
            minflow = min(minflow, cap[u][v] - flow[u][v]);
            v = u;
        }
        for(int v = t ; v != s;) {
            int u = p[v];
            flow[u][v] += minflow;
            flow[v][u] -= minflow;
            v = u;
        }
        f += cost[t]*minflow;
        //cout << "f == " << f << endl;
    }
}


int main() {
    int n, m;
    while(cin >> n >> m) {
        cap.assign(n+2, vector<long long>(n+2));
        flow.assign(n+2, vector<long long>(n+2));
        adjlist.assign(n+2, vector<long long>());
        Cost.assign(n+2, vector<long long>(n+2));
        s = 0;
        t = n+1;
        while(m--) {
            int a, b, w;
            cin >> a >> b >> w;
            cap[a][b] = cap[b][a] = 1;
            Cost[a][b] = Cost[b][a] = w;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);

        }
        int d, k;
        cin >> d >> k;
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= n ; j++) {
                if(cap[i][j]) {
                    cap[i][j] = k;
                }
            }
        }
        cap[s][1] = d;
        cap[n][t] = d;
        adjlist[s].push_back(1);
        adjlist[n].push_back(t);
        f = 0;
        maxflow(n);

        if(flow[n][t] != d) {
            //cout << flow[n][t] << endl;
            cout << "Impossible." << endl;
        }else{
            cout << f << endl;
        }
    }
}
