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
vector <vector<int>> cap, Gw, adjlist, flow;
int f, s, t, n;
vector <int> p, cost;



void SPFA() {
    p.assign(n+2, 0);
    cost.assign(n+2, 0);
    for(int i = 1 ; i <= n+1 ; i++) {
        cost[i] = INT_MAX;
    }
    cost[s] = 0;
    queue <int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adjlist[u]) {
            if(cost[u] + Gw[u][v] < cost[v] && cap[u][v] > flow[u][v]) {
                cost[v] = cost[u] + Gw[u][v];
                p[v] = u;
                q.push(v);
            }
            if(cost[u] - Gw[v][u] < cost[v] && flow[v][u] > 0) {
                cost[v] = cost[u] - Gw[v][u];
                p[v] = u;
                q.push(v);
            }
        }
    }

}

bool maxflow() {
    int times = 0;
    while(true) {
        SPFA();
        if(cost[t] == INT_MAX) break;
        for(int v = t ; v != s;) {
            int u = p[v];
            flow[u][v] -= 1;
            flow[v][u] += 1;
            v = u;
        }
        times++;
        f += cost[t];
        swap(s, t);
        if(times >= 2) break;
    }
    if(times < 2) return false;
    return true;
}


int main() {
    int m;
    while(cin >> n) {
        if(!n) break;
        cap.assign(n+2, vector<int> (n+2));
        flow.assign(n+2, vector<int> (n+2));
        Gw.assign(n+2, vector<int> (n+2));
        adjlist.assign(n+2, vector<int>());
        cin >> m;
        s = 1;
        t = n+1;
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            cap[a][b] = cap[b][a] = 1;
            Gw[a][b] = Gw[b][a] = c;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        cap[s][1] = cap[1][s] = cap[t][n] = cap[n][t] = 2;
        Gw[s][1] = Gw[1][s] = Gw[t][n] = Gw[n][t] = 0;
        adjlist[0].push_back(1);
        adjlist[1].push_back(0);
        adjlist[n].push_back(t);
        adjlist[t].push_back(n);
        f = 0;
        if(maxflow()) {
            cout << f << endl;
        }else{
            cout << "Back to jail" << endl;
        }
    }
}
