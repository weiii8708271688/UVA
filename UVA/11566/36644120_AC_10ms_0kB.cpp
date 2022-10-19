#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int x, t;
    while(cin >> n >> x >> t >> k) {
        if(!n && !x && !t && !k) break;
        n++;
        int w[k*2];
        int price[k*2];
        for(int i = 0 ; i < k ; i++) {
            cin >> price[i];
            price[i+k] = price[i];
            int sum = 0;
            for(int j = 0 ; j < n ; j++) {
                int temp;
                cin >> temp;
                sum += temp;
            }
            w[i] = w[i+k] = sum;
        }

        int price_limit = (n * x) / (float) 1.1 - (n * t);
        int dp[n*2+1][price_limit+1] = {0};
        for(int i = 0 ; i <= n*2 ; i++) {
            for(int j = 0 ; j <= price_limit ; j++) {
                dp[i][j] = 0;
            }
        }

        for(int z = 0 ; z < k*2 ; z++) {
            for(int i = n*2 ; i > 0 ; i--) {
                for(int j = price_limit ; j >= price[z] ; j--) {
                    dp[i][j] = max(dp[i][j], max(dp[i-1][j-price[z]]+w[z], dp[i-1][j]));
                }
            }
        }

        //cout << "final ans == " << dp[k*2-1][price_limit-1] << endl;

        int mx = INT_MIN;
        for (int i = 0; i <= 2*n; ++i) mx = max(dp[i][price_limit], mx);


        cout << fixed << setprecision(2) << (double)mx/n << endl;


    }
}
