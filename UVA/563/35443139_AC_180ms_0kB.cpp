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
vector <vector<int>> G, adjlist, pos;
int f, s, t;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void maxflow(int n) {
    while(true) {
        int flow[n*2+2] = {0};
        int p[n*2+2] = {0};
        flow[s] = INT_MAX;
        queue <int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v :adjlist[u]) {
                if(!flow[v] && G[u][v] > 0) {
                    flow[v] = min(flow[u], G[u][v]);
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        if(!flow[t]) return;
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
    int Case;
    cin >> Case;
    while(Case--) {
        int row, col, b;
        cin >> row >> col >> b;
        int count = 1;
        G.assign(row*col*2+2, vector <int> (row*col*2+2));
        adjlist.assign(row*col*2+2, vector <int>());
        s = 0;
        t = row*col*2+1;
        int pos[row+1][col+1];
        for(int i = 1 ; i <= row ; i++) {
            for(int j = 1 ; j <= col ; j++) {
                pos[i][j] = count++;
                int u = pos[i][j];
                G[u][u+row*col] = 1;
                adjlist[u].push_back(u+row*col);
                if(i == 1 || j == 1 || i == row || j == col) {
                    G[u+row*col][t] = 1;
                    adjlist[u+row*col].push_back(t);
                }
            }
        }

        for(int i = 1 ; i <= row ; i++) {
            for(int j = 1 ; j <= col ; j++) {
                int u = pos[i][j];
                for(int z = 0 ; z < 4 ; z++) {
                    int tx = i + dx[z];
                    int ty = j + dy[z];
                    if(tx > 0 && ty > 0 && tx <= row && ty <= col) {
                        int v = pos[tx][ty];
                        G[u+row*col][v] = 1;
                        adjlist[u+row*col].push_back(v);
                    }
                }
            }
        }

        for(int j = 0 ; j < b ; j++) {
            int trow, tcol;
            cin >> trow >> tcol;
            int u = pos[trow][tcol];
            G[s][u] = 1;
            adjlist[s].push_back(u);
            for(int z = 0 ; z < 4 ; z++) {
                int tx = trow + dx[z];
                int ty = tcol + dy[z];
                if(tx > 0 && ty > 0 && tx <= row && ty <= col) {
                    int v = pos[tx][ty];
                    G[v+row*col][u] = 0;
                }
            }
        }

        f = 0;
        maxflow(row*col);
        if(f == b) {
            cout << "possible" << endl;
        }else{
            cout << "not possible" << endl;
        }
    }
}
