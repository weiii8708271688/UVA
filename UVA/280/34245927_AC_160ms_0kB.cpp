#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> G;
vector <bool> dfn;

void dfs(int u) {
    for(auto& v: G[u])
        if(!dfn[v]) {
            dfn[v] = true;
            dfs(v);
        }
}



int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        G.assign(n+1, vector<int>());
        int a, b;
        while(cin >> a) {
            if(!a) break;
            while(cin >> b) {
                if(!b) break;
                G[a].push_back(b);
            }
        }
        int t;
        cin >> t;
        while(t--) {
            int start;
            cin >> start;
            dfn.assign(n+1, false);
            dfs(start);
            vector <int> ans;
            for(int i = 1 ; i <= n ; i++) {
                if(!dfn[i]) ans.push_back(i);
            }
            if(ans.empty()) cout << "0" << endl;
            else{
                cout << ans.size();
                for(int i = 0 ; i < ans.size() ; i++) {
                    cout << " " << ans[i];
                }
                cout << endl;
            }
        }
    }
}
