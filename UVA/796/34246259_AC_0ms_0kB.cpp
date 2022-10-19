#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

vector <vector<int>> G;
vector <int> dfn, low;
int times;
vector <pair<int, int>> bridge;

void dfs(int u, int par) {
    times++;
    dfn[u] = low[u] = times;
    for(auto& v : G[u]) {
        if(!dfn[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                bridge.push_back(make_pair(min(u, v), max(u, v)));
            }
        }else if(v != par) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}


int main() {
    int n;
    while(cin >> n){
        G.assign(n, vector <int>());
        dfn.assign(n, 0);
        low.assign(n, 0);
        bridge.clear();
        times = 0;
        for(int i = 0 ; i < n ; i++) {
            int a, b, num;
            cin >> a;
            char ch;
            cin >> ch >> num >> ch;
            while(num--) {
                cin >> b;
                G[a].push_back(b);
            }
        }
        for(int i = 0 ; i < n ; i++) {
            if(!dfn[i]) {
                dfs(i, -1);
            }
        }
        cout << bridge.size() << " critical links" << endl;
        sort(bridge.begin(), bridge.end());
        for(int i = 0 ; i < bridge.size() ; i++) {
            cout << bridge[i].first << " - " << bridge[i].second << endl;
        }
        cout << endl;
    }
}
