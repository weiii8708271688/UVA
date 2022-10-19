#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
#include <map>
using namespace std;

int main() {
    int c, s, q, testcase = 0;
    while(cin >> c >> s >> q) {
        if(!c) break;
        if(testcase) cout << endl;
        vector <int> node[c+1];
        int noise[c+1][c+1];
        int ans[c+1][c+1];
        for(int i = 1 ; i <= c ; i++)  {
            for(int j = 1 ; j <= c ; j++) {
                noise[i][j] = -1;
                ans[i][j] = -1;
            }
        }
        while(s--) {
            int c1, c2, n;
            cin >> c1 >> c2 >> n;
            if(c1 > c || c2 > c) continue;
            noise[c1][c2] = n;
            noise[c2][c1] = n;
            node[c1].push_back(c2);
            node[c2].push_back(c1);
        }
        for(int i = 1 ; i <= c ; i++) {
            queue <int> qu;
            qu.push(i);
            bool inqueue[c+1] = {0};
            inqueue[i] = true;
            while(!qu.empty()) {
                int n = qu.front();qu.pop();
                inqueue[n] = false;
                for(int j = 0 ; j < node[n].size() ; j++) {
                    int m = node[n][j];
                    if(ans[i][m] == -1) {
                        ans[i][m] = max(noise[n][m], ans[i][n]);
                        inqueue[m] = true;
                        qu.push(m);
                    }else if(ans[i][m] > max(noise[n][m], ans[i][n])) {
                        ans[i][m] = max(noise[n][m], ans[i][n]);
                        if(!inqueue[m]) {
                            inqueue[m] = true;
                            qu.push(m);
                        }
                    }
                }
                
            }
        }
        cout << "Case #" << ++testcase << endl;
        while(q--) {
            int n, m;
            cin >> n >> m;
            if(ans[n][m] == -1) {
                cout << "no path" << endl;
            }else{
                cout << ans[n][m] << endl;
            }
        }
    }
}
