#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;
//not me

int main() {
    int n;
    cin >> n;
    while(n--) {
        int m, k, sum = 0;
        cin >> m >> k;
        int num[m];
        for(int i = 0 ; i < m ; i++) {
            cin >> num[i];
            num[i] = abs(num[i])%k;
        }
        bool dp[m+1][k];
        for(int i = 0 ; i <= m ; i++) {
            for(int j = 0 ; j < k ; j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < k ; j++) {
                if(dp[i][j]) {
                    dp[i+1][(j+k+num[i])%k] = true;
                    dp[i+1][(j+k-num[i])%k] = true;
                }
            }
        }
        
        if(dp[m][0]) {
            cout << "Divisible" << endl;
        }else{
            cout << "Not divisible" << endl;
        }

    }
}
