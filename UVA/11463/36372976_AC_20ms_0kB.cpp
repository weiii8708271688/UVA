#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, t = 1;
    cin >> T;
    while(T--) {
        int n, r;
        cin >> n >> r;
        int dis[n][n];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                dis[i][j] = INT_MAX;
            }
            dis[i][i] = 0;
        }
        for(int i = 0 ; i < r ; i++) {
            int a, b;
            cin >> a >> b;
            dis[a][b] = dis[b][a] = 1;
        }

        for(int z = 0 ; z < n ; z++) {
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < n ; j++) {
                    if(dis[i][z] + dis[z][j] > 0) dis[i][j] = min(dis[i][j], dis[i][z] + dis[z][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                //cout << i << " -> " << j << " need " << dis[i][j] << endl;
            }
        }


        int s, d;
        cin >> s >> d;

        for(int i = 0 ; i < n ; i++) {
            ans = max(ans, dis[s][i] + dis[i][d]);
        }
        cout << "Case " << t++ << ": " << ans << endl;

    }
}

