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

int G[38][38];
int f, sum;

void newjob(string s) {
    int ch = s[0] - 'A' + 1;
    int num = s[1] - '0';
    G[0][ch] = num;
    sum += num;
    for(int i = 3 ; i < s.size() ; i++) {
        if(s[i] == ';') return;
        num = s[i] - '0' + 27;
        G[ch][num] = 1;
    }
}

void maxflow() {
    while(true) {
        queue <int> q;
        q.push(0);
        int flow[38] = {0};
        flow[0] = INT_MAX;
        int p[38];
        for(int i = 0 ; i < 38 ; i++) p[i] = -1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 27 ; v < 38 ; v++) {
                if(!flow[v] && G[u][v] > 0) {
                    p[v] = u;
                    flow[v] = min(flow[u], G[u][v]);
                    q.push(v);
                }
            }
            for(int v = 26 ; v > 0 ; v--) {
                if(!flow[v] && G[u][v] > 0) {
                    p[v] = u;
                    flow[v] = min(flow[u], G[u][v]);
                    q.push(v);
                }
            }
        }
        if(!flow[37]) break;
        for(int v = 37 ; v != 0 ;) {
            int u = p[v];
            G[u][v] -= flow[37];
            G[v][u] += flow[37];
            v = u;
        }
        f += flow[37];
    }
}


int main() {
    string s;
    while(getline(cin,s)) {
        if(s == "") break;
        for(int i = 0 ; i < 38 ; i++) {
            for(int j = 0 ; j < 38 ; j++) {
                G[i][j] = 0;
            }
        }
        for(int i = 27 ; i < 37 ; i++) {
            G[i][37] = 1;
        }
        f = sum = 0;
        do {
            if(s == "") break;
            newjob(s);
        }while(getline(cin,s));
        maxflow();
        if(f == sum) {
            for(int i = 27 ; i < 37 ; i++) {
                for(int j = 1 ; j < 27 ; j++) {
                    if(G[i][j] == 1) {
                        cout << char(j+'A'-1);
                        break;
                    }
                    if(j == 26) cout << "_";
                }
            }
            cout << endl;
        }else{
            cout << "!" << endl;
        }
    }
}
