#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    long long bc[51][51][51];
    for(n = 1 ; n < 51 ; n++) {
        for(k = 1 ; k < 51 ; k++) {
            for(m = 1 ; m < 51 ; m++) {
                bc[n][k][m] = 0;
            }
        }
    }
    for(int i = 1 ; i < 51 ; i++) {
        for(int j = i ; j < 51 ; j++) {
            bc[i][1][j] = 1;
        }
    }
    for(n = 1 ; n < 51 ; n++) {
        for(k = 1 ; k < 51 ; k++) {
            for(m = 1 ; m < 51 ; m++) {
                if(m > n) {
                    bc[n][k][m] = bc[n][k][n];
                    continue;
                }
                for (int i = 1; i <= m; i++) {
                    bc[n][k][m] += bc[n - i][k - 1][m];
                }
            }
        }
    }
    while(cin >> n >> k >> m) {
        cout << bc[n][k][m] << endl;
    }
}



