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
#include <queue>
#include <unordered_set>
using namespace std;


int times;
vector <vector<int> > G;
vector <bool> dfn;
vector <int> V;

void dfs(int u) {
    dfn[u] = true;
    for(auto& v: G[u]) if(!dfn[v]) dfs(v);
}




int main() {
    int n, m, t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        dfn.assign(n+1, false);
        G.assign(n+1, vector<int>());
        V.clear();
        while(m--) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++) {
            if(!dfn[i]) {
                dfs(i);
                V.push_back(i);
            }
        }
        dfn.assign(n+1, false);
        for(int i = V.size()-1 ; i >= 0 ; i--) {
            if(!dfn[V[i]]) {
                dfs(V[i]);
                ans++;
            }
        }
        cout << ans << endl;
    }
}
