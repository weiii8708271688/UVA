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
    int c, t = 1;
    cin >> c;
    while(c--) {
        int n, m;
        cin >> n >> m;
        edge edges[m];
        for(int i = 0 ; i < m ; i++) {
            cin >> edges[i].a >> edges[i].b >> edges[i].w;
        }
        int ans[n];
        for(int i = 0 ; i < n ; i++) ans[i] = 999999;
        ans[0] = 0;
        for(int i = 0 ; i < n+1 ; i++) {
            for(auto j: edges) {
                if(ans[j.b] > ans[j.a] + j.w) {
                    ans[j.b] = ans[j.a] + j.w;
                }
            }
        }
        bool change = false;
        for(auto j: edges) {
            if(ans[j.b] > ans[j.a] + j.w) {
                change = true;
            }
        }
        if(change) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
}
