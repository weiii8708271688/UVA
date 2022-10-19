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
    int n, r, q, t = 1;
    while(cin >> n) {
        int busy[n+1];
        for(int i = 1 ; i <= n ; i++) {
            cin >> busy[i];
        }
        cin >> r;
        edge edges[r];
        for(int i = 0 ; i < r ; i++) {
            cin >> edges[i].a >> edges[i].b;
            edges[i].w = pow(busy[edges[i].b] - busy[edges[i].a], 3);
        }
        cin >> q;
        long long ans[n+1];
        for(int i = 0 ; i < n+1 ; i++) ans[i] = INT_MAX;
        ans[1] = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            for(auto [a,b,w]:edges) {
                if(ans[b] > ans[a] + w && ans[a] != INT_MAX) {
                    ans[b] = ans[a]+w;
                }
            }
        }
        bool bad[n+1] = {0};
        bool again = true;
        for(auto [a,b,w]:edges) {
            if(ans[b] > ans[a] + w && ans[a] != INT_MAX) {
                bad[b] = true;
                ans[b] = ans[a] + w;
                //cout << "catch: " << a << endl;
            }
        }
        cout << "Set #" << t++ << endl;
        while(q--) {
            int tmp;
            cin >> tmp;
            if(bad[tmp] || ans[tmp] == INT_MAX || ans[tmp] < 3) cout << "?" << endl;
            else cout << ans[tmp] << endl;
        }
    }
}
