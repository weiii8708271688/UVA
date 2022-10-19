#include <bits/stdc++.h>
using namespace std;

struct Coin{
    int convent;
    int info;
};

int m, s;
vector <Coin> coin;

int solve() {
    int dp[301][301];
    memset(dp, 301, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0 ; i < 301 ; i++) {
        for(int j = 0 ; j < 301 ; j++) {
            for(int z = 0 ; z < m ; z++) {
                int c = coin[z].convent;
                int in = coin[z].info;
                if(i >= c && j >= in) {
                    dp[i][j] = min(dp[i][j], dp[i-c][j-in]+1);
                }
            }
        }
    }

    int ans = 301;
    for(int i = 0 ; i < 301 ; i++) {
        for(int j = 0 ; j < 301 ; j++) {
            if(i*i+j*j == s*s) {
                ans = min(ans, dp[i][j]);
            }
        }
    }

    return ans;
}


int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> m >> s;
        coin.assign(m, Coin());
        for(int i = 0 ; i < m ; i++) {
            cin >> coin[i].convent >> coin[i].info;
        }

        int ans = solve();
        if(ans > 300) {
            cout << "not possible" << endl;
        }else{
            cout << ans << endl;
        }


    }
}
