#include <bits/stdc++.h>
using namespace std;


static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int main() {
    long long dp[67][67][2] = {0};
    dp[1][0][0] = dp[1][1][1] = 1;
    dp[1][1][0] = dp[1][0][1] = 0;
    for(int i = 2 ; i < 66 ; i++) {
        for(int j = 0 ; j < 66 ; j++) {
            if(j > 0) dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1];
            dp[i][j][0] = dp[i-1][j+1][1] + dp[i-1][j][0];
        }
    }
    int n, s;
    while(cin >> n >> s) {
        if(s < 0 && n < 0) break;
        cout << dp[n][s][0] + dp[n][s][1] << endl;
    }
}

