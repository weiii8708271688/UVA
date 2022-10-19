#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int dp[102][102];
    for(int i = 0 ; i < 101 ; i++) {
        for(int j = 0 ; j < 101 ; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i = 0 ; i < 101 ; i++) {
        dp[i][1] = 1;
        dp[0][i] = 1;
    }
    for(k = 2 ; k < 101 ; k++) {
        for(n = 1 ; n < 101 ; n++) {
            for(int i = 0 ; i <= n ; i++) {
                dp[n][k] = (dp[n][k] + dp[n-i][k-1])%1000000;
            }

        }
    }
    while(cin >> n >> k) {
        if(!n && !k) break;
        cout << dp[n][k] << endl;
    }
}



