#include <iostream>
#include <vector>
using namespace std;


vector <vector<int>> G;
vector <bool> dfn;
vector <int> V;

void dfs(int u) {
    dfn[u] = true;
    for(auto& v: G[u]) if(!dfn[v]) dfs(v);
}



int main() {
    int n, m, t;
    cin >> t;
    for(int c = 1 ; c <= t ; c++) {
        cin >> n >> m;
        dfn.assign(n+1, false);
        V.clear();
        G.assign(n+1, vector<int>());
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
            int u = V[i];
            if(!dfn[u]) {
                dfs(u);
                ans++;
            }
        }
        cout <<"Case " << c << ": " << ans << endl;
    }
}
