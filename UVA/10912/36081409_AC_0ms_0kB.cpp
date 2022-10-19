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

int main() {
    int len, sum, t = 1;
    int dp[27][27][352];
    for(len = 0 ; len < 27 ; len++) {
        for(sum = 0 ; sum < 352 ; sum++) {
            for(int i = 0 ; i < 27 ; i++) {
                dp[i][len][sum] = 0;
            }
        }
    }
    for(int i = 1 ; i < 27 ; i++) {
        dp[i][1][i] = 1;
    }
    for(int i = 1 ; i < 27 ; i++) {
        for(int j = 1 ; j < 27 ; j++) {
            for(int k = 1 ; k < 352 ; k++) {
                dp[i][j][k] += dp[i-1][j][k];
                if(k >= i) dp[i][j][k] += dp[i-1][j-1][k-i];
            }
        }
    }
    while(cin >> len >> sum) {
        if(!len && !sum) break;
        cout << "Case " << t++ << ": ";
        if(len > 26 || sum > 351) {
            cout << "0" << endl;
            continue;
        }else{
            cout << dp[26][len][sum] << endl;
        }
    }
}

