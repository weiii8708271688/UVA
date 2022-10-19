#include <bits/stdc++.h>
using namespace std;


vector<int> prime;
vector<bool> prime_list;

void prime_number() {
    prime_list.assign(1121, true);
    for(int i = 2 ; i < 1121 ; i++) {
        if(prime_list[i]) {
            prime.push_back(i);
            for(int j = i+i ; j < 1121 ; j+=i) {
                prime_list[j] = false;
            }
        }
    }
}


int main() {
    int n, k;
    prime_number();
    int Size = prime.size();
    int dp[1121][15] = {0};
    dp[0][0] = 1;
    for(int k = 0 ; k < Size ; k++) {
        for(int i = 1120 ; i >= prime[k] ; i--) {
            for(int j = 1 ; j < 15 ; j++) {
                dp[i][j] += dp[i-prime[k]][j-1];
            }
        }
    }

    while(cin >> n >> k) {
        if(!n && !k) break;
        cout << dp[n][k] << endl;
    }
}
