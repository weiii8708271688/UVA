#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//not me

vector< vector<int> > G;
vector<int> dfn, low, bridge;
int dep;

void dfs(int u, int par)
{
    dfn[u] = low[u] = ++dep;

    for (auto& v : G[u])
    {
        if (!dfn[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (v != par) low[u] = min(low[u], low[v]);     

        if (low[v] > low[u]) bridge.emplace_back(v), bridge.emplace_back(u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    while (cin >> n >> m)
    {
        // init
        G.assign(n + 1, vector<int>());
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        bridge.clear();
        dep = 0;
        int con1 = 0, con0 = 0;

        // store data
        while (m--)
        {
            cin >> a >> b;
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        }

        // find bridge connected component
        for (int i = 1; i <= n; ++i)
            if (!dfn[i])
            {
                size_t s = bridge.size();
                dfs(i, -1);
                if (s == bridge.size()) ++con0;
            }

        // solve
        if (bridge.size() == 0 && con0 == 1) cout << "0\n";
        else
        {
            map<int, int> m;
            for (int i = 1; i <= n; ++i) 
            {           
                m[low[i]] += 0;
                for (auto& v : G[i]) if (low[v] != low[i]) ++m[low[i]];
            }

            for (auto& [__, de] : m) if (de == 1) ++con1;

            cout << con0 + (con1 + 1) / 2 << "\n";           
        }        
    }

    return 0;
}