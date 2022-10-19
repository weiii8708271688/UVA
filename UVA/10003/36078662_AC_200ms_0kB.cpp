#include <bits/stdc++.h>
using namespace std;


static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector <int> cut;
vector <vector<int>> dp;
int n;

int solve(int L, int R) {
    if(dp[L][R] != -1) return dp[L][R];
    for(int i = 1 ; i <= n ; i++) {
        if(i < R && i > L) {
            if(dp[L][R] == -1) dp[L][R] = cut[R]-cut[L]+solve(L, i)+solve(i, R);
            else dp[L][R] = min(dp[L][R], cut[R]-cut[L]+solve(L, i)+solve(i, R));
        }
    }
    //cout << "dp[" << L << "][" << R << "] == " << dp[L][R] << endl;
    return dp[L][R];
}


int main() {
    int l;
    while(cin >> l) {
        if(!l) break;
        cin >> n;
        cut.assign(n+2, 0);
        dp.assign(n+2, vector<int>(n+2, -1));
        for(int i = 1 ; i <= n ; i++) {
            cin >> cut[i];
        }
        cut[n+1] = l;
        for(int i = 0 ; i <= n ; i++) {
            dp[i][i+1] = 0;
        }
        solve(0, n+1);
        cout << "The minimum cutting is " << dp[0][n+1] << "." << endl;
    }
}

