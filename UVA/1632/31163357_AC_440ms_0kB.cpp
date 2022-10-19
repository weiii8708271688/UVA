#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <limits.h>
using namespace std;

int INF = 1000000;
int dp[10000][10000][2];

int main() {
    int n;
    while(cin >> n) {
        int x[n], t[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> x[i] >> t[i];
            dp[i][i][0] = 0;
            dp[i][i][1] = 0;
        }
        for(int l = n-1 ; l >= 0 ; l--) {
            for(int r = l+1 ; r < n ; r++) {
                dp[l][r][0] = min(dp[l+1][r][0]+(x[l+1] - x[l]), dp[l+1][r][1]+ (x[r] - x[l]));
                dp[l][r][1] = min(dp[l][r-1][0]+(x[r]   - x[l]), dp[l][r-1][1]+ (x[r]-x[r-1]));
                if(dp[l][r][0] >= t[l]) dp[l][r][0] = INF;
                if(dp[l][r][1] >= t[r]) dp[l][r][1] = INF;
            }
        }
        int ans = min(dp[0][n-1][0], dp[0][n-1][1]);
        if(ans == INF) cout << "No solution" << endl;
        else cout << ans << endl;
    }
}
