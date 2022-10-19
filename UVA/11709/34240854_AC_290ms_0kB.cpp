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
map <string, int> name;
vector <vector<int>> G, GT;
vector <bool> dfn;
vector <pair<int, int>> finish;
vector <int> V;


void dfs(int u) {
    times++;
    dfn[u] = true;
    for(auto& v: G[u]) if(!dfn[v]) dfs(v);
    times++;
    finish.push_back(make_pair(u, times));
}

void dfs2(int u) {
    dfn[u] = true;
    for(auto& v: GT[u]) if(!dfn[v]) dfs2(v);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}


int main() {
    int n, m;
    string s;
    while(cin >> n >> m) {
        if(!n && !m) break;
        times = 0;
        dfn.assign(n+1, false);
        finish.clear();
        G.assign(n+1, vector<int>());
        GT.assign(n+1, vector<int>());
        V.clear();
        cin.ignore();
        for(int i = 1 ; i <= n ; i++) {
            getline(cin, s);
            name[s] = i;
        }
        while(m--) {
            int a, b;
            getline(cin, s);
            a = name[s];
            getline(cin, s);
            b = name[s];
            G[a].push_back(b);
            GT[b].push_back(a);
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++) {
            if(!dfn[i]) {
                dfs(i);
            }
        }
        dfn.assign(n+1, false);
        sort(finish.begin(), finish.end(), cmp);
        for(int i = 0 ; i < finish.size() ; i++) {
            int u = finish[i].first;
            if(!dfn[u]) {
                dfs2(u);
                ans++;
            }
        }
        cout << ans << endl;
    }
}
