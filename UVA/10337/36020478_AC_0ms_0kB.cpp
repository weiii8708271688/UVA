#include <bits/stdc++.h>
using namespace std;


int drow[3] = {0, -1, 1};
int fuel[3] = {30, 60, 20};

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n;
        m = n/100;
        int grid[10][m+1];
        int ans[10][m+1];
        for(int i = 9 ; i >= 0 ; i--) {
            for(int j = 0 ; j <= m ; j++) {
                ans[i][j] = INT_MAX;
                if(j == m) continue;
                cin >> grid[i][j];
            }
        }
        ans[0][0] = 0;
        for(int j = 0 ; j <= m ; j++) {
            for(int i = 0 ; i < 10 ; i++) {
                int tcol = j-1, trow;
                for(int z = 0 ; z < 3 ; z++) {
                    trow = i + drow[z];
                    if(tcol >= 0 && trow >= 0 && trow < 10 && ans[trow][tcol] != INT_MAX) {
                        ans[i][j] = min(ans[i][j], ans[trow][tcol] + fuel[z] - grid[trow][tcol]);
                    }
                }
            }
        }
        cout << ans[0][m] << endl << endl;
    }
}
