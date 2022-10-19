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

struct edge{
    int a, b, w;
};


int main() {
    int n;
    while(cin >> n) {
        if(n == -1) break;
        vector <int> G[n+1];
        vector <int> G_inv[n+1];
        int value[n+1];
        for(int i = 1 ; i <= n ; i++) {
            cin >> value[i];
            int num;
            cin >> num;
            while(num--) {
                int b;
                cin >> b;
                G[i].push_back(b);
                G_inv[b].push_back(i);
            }
        }
        int ans[n+1];
        //int par[n+1];
        for(int i = 0 ; i <= n ; i++) ans[i] = INT_MAX;
        ans[1] = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            for(int u = 1 ; u <= n ; u++) {
                for(auto v: G[u]) {
                    if(ans[u] != INT_MAX && ans[v] > ans[u] - value[v] && ans[u] - value[v] < 100) {
                        ans[v] = ans[u] - value[v];
                        //par[v] = u;
                    }
                }
            }
        }
        bool pass = false;
        bool though[n+1] = {0};
        queue <int> q;
        q.push(n);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            though[cur] = true;
            for(auto v: G_inv[cur]) {
                if(!though[v]) {
                    though[v] = true;
                    q.push(v);
                }
            }
        }
//        for(int i = 1 ; i <= n ; i++) {
//            cout << i << ": ";
//            cout << (though[i]?"pass":"fail") << endl;
//        }
        for(int u = 1 ; u <= n ; u++) {
            for(auto v: G[u]) {
                if(ans[u] != INT_MAX && ans[v] > ans[u] - value[v] && ans[u] - value[v] < 100 && though[v]) {
                    //cout << u << "->" << v << "has change" << endl;
                    pass = true;
                }
            }
        }
//        for(int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
//        cout << endl;
        if(pass || ans[n] != INT_MAX) {
            cout << "winnable" << endl;
        }else{
            cout << "hopeless" << endl;
        }
    }
}
