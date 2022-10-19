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
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void maxflow(int n) {
    while(true) {
        queue <int> q;
        q.push(s);
        int flow[n*2+2] = {0};
        flow[s] = INT_MAX;
        int p[n*2+2];
        for(int i = 0 ; i <= n*2+1 ; i++) p[i] = -1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 1 ; v <= n*2+1 ; v++) {
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
    int x, y, p;
    while(cin >> x >> y >> p) {
        string grid[x];
        int num[x][y];
        int Size = 0;
        for(int i = 0 ; i < x ; i++) {
            cin >> grid[i];
            for(int j = 0 ; j < grid[i].size() ; j++) {
                if(grid[i][j] != '~') num[i][j] = ++Size;
            }
        }
        G.assign(Size*2+2, vector<int>(Size*2+2));
        s = 0;
        t = Size*2+1;
        for(int i = 0 ; i < x ; i++) {
            for(int j = 0 ; j < y ; j++) {
                if(grid[i][j] == '~') continue;
                //cout << "i: " << i << " j: " << j << endl;
                int u = num[i][j], v;
                int tx, ty;
                if(grid[i][j] == '#') {
                    G[u][t] = p;
                }else if(grid[i][j] == '*') {
                    G[0][u] = 1;
                }
                for(int z = 0 ; z < 4 ; z++) {
                    tx = i + dx[z];
                    ty = j + dy[z];
                    if(tx < 0 || ty < 0 || tx == x || ty == y || grid[tx][ty] == '~') continue;
                    //cout << "tx: " << tx << " ty: " << ty << endl;
                    v = num[tx][ty];
                    if(grid[i][j] == '@' || grid[i][j] == '#') {
                        G[u+Size][v] = INT_MAX;
                        G[u][u+Size] = INT_MAX;
                    }else{
                        G[u+Size][v] = 1;
                        G[u][u+Size] = 1;
                    }
                }
            }
        }
        f = 0;
        maxflow(Size);
        cout << f << endl;
    }
}
