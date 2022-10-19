#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

int dp[52][52];
int c[52];


int main() {
    int l, n;
    while(cin >> l) {
        if(!l) break;
        cin >> n;
        for(int i = 1 ; i <= n ; i++) {
            cin >> c[i];
        }
        n++;
        c[0] = 0;
        c[n] = l;
        for(int i = 0 ; i < 52 ; i++) {
            for(int j = 0 ; j < 52 ; j++) {
                dp[i][j] = 0;
            }
        }
        for(int r = 2 ; r <= n ; r++) {
            for(int b = 0 ; b < n ; b++) {
                int e = b + r;
                if(e > n) break;
                dp[b][e] = INT_MAX;
                for(int m = b+1 ; m < e ; m++) {
                    int temp = dp[b][m] + dp[m][e] + c[e] - c[b];
                    if(temp < dp[b][e]) dp[b][e] = temp;
                }
            }
        }
        cout << "The minimum cutting is " << dp[0][n] << "." << endl;
    }
}


