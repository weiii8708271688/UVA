#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, d, m, T = 1;
    while(cin >> n >> q) {
        if(!n && !q) break;
        int t = 1;
        int num[n];
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            cin >> num[i];
        }



        cout << "SET " << T++ << ":" << endl;
        for(int i = 0 ; i < q ; i++) {
            long long ans = 0;
            cin >> d >> m;
            int num2[n];
            for(int i = 0 ; i < n ; i++) {
                num2[i] = num[i]%d;
                if(num2[i]<0) num2[i] += d;
            }

            long long dp[201][11] = {0};

            for(int i = 0 ; i < 201 ; i++) {
                for(int j = 0 ; j < 11 ; j++) {
                    dp[i][j] = 0LL;
                }
            }


            dp[0][0] = 1LL;





            for(int k = 0 ; k < n ; k++) {
                for(int i = m ; i > 0 ; i--) {
                    for(int j = 200 ; j >= num2[k] ; j--) {
                        dp[j][i] += dp[j-num2[k]][i-1];
                    }
                }
            }



            for(int i = 0 ; i < 201 ; i+=d) {
                ans += dp[i][m];
            }
            cout << "QUERY " << t++ << ": " << ans << endl;
        }

    }
}
