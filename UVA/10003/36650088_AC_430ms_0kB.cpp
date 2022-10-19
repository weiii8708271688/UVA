#include<bits/stdc++.h>

using namespace std;

vector<int> cut;
vector<vector<int> > dp;

int n, m;


int solve(int L, int R) {
    if(L >= R) return INT_MAX;
    if(dp[L][R] != 0) return dp[L][R];


    for(int i = 1 ; i <= m ; i++) {
        if(i > L && i < R) {
            if(dp[L][R] == 0) dp[L][R] = cut[R]-cut[L]+solve(L, i)+solve(i, R);
            dp[L][R] = min(dp[L][R], cut[R]-cut[L]+solve(L, i)+solve(i, R));
        }
    }

    return dp[L][R];
}







int main() {
    while(cin >> n) {
        if(!n) break;
        cin >> m;
        cut.assign(m+2, 0);
        dp.assign(m+2, vector<int>(m+2, 0));
        for(int i = 1 ; i <= m ; i++) {
            cin >> cut[i];
        }
        for(int i = 0 ; i < m+2 ; i++) {
            dp[i][i] = 0;
        }
        cut[m+1] = n;

        cout << "The minimum cutting is " << solve(0, m+1) << "." << endl;
    }
}
