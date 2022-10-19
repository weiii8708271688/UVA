#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--) {
        int m, s;
        int dp[20001];
        cin >> s >> m;
        int coin[m];
        int sum = 0;
        for(int i = 0 ; i < m ; i++) {
            cin >> coin[i];
            if(sum < s) sum += coin[i];
        }

        for(int i = 1 ; i <= 20001 ; i++) {
            dp[i] = m+1;
        }
        dp[0] = 0;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 20001 ; j >= coin[i] ; j--) {
                dp[j] = min(dp[j], dp[j-coin[i]]+1);
            }
        }


        int price = s;
        while(dp[price] == m+1) price++;

        cout << price << " " << dp[price] << endl;


    }
}
