#include <bits/stdc++.h>
using namespace std;





int main() {
    int T, t = 1;
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int grid[n][m];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++){
                cin >> grid[i][j];
            }
        }

        int ans = INT_MAX, area = INT_MIN;
        int max1D[n] = {0};
        for(int L = 0 ; L < m ; L++) {
            for(int i = 0 ; i < n ; i++) {
                max1D[i] = 0;
            }
            for(int R = L ; R < m ; R++) {
                int temp = 0;
                int local_ans = INT_MIN, local_area = 0, temp_area = (R-L+1), l = 0, r = 0;
                //cout << " L == " << L << " R == " << R << endl;
                for(int r = 0 ; r < n ; r++) {
                    max1D[r] += grid[r][R];
                    temp += max1D[r];

                    local_area += temp_area;


                    while(temp > k) {
                        local_area -= temp_area;
                        temp -= max1D[l];
                        l++;
                    }

                    if(local_area > area) {
                        area = local_area;
                        ans = temp;
                    }else if(local_area == area) {
                        ans = min(ans, temp);
                    }


                    //cout << "Max1D[" << i << "] == " << max1D[i-t] << endl;

                }
                //cout << "local_ans == " << local_ans << endl << endl << endl;
            }
        }


        cout << "Case #" << t++ << ": " << area << " " << ans << endl;
    }
}

