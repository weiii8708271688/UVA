#include <bits/stdc++.h>
using namespace std;





int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int grid[n*2][n*2];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++){
                cin >> grid[i][j];
                grid[i+n][j] = grid[i][j+n] = grid[i+n][j+n] = grid[i][j];
            }
        }
        
        int ans = INT_MIN;
        int max1D[n] = {0};
        for(int t = 0 ; t < n ; t++) {
            for(int L = 0 ; L < n ; L++) {
                for(int i = 0 ; i < n ; i++) {
                    max1D[i] = 0;
                }
                for(int R = L ; R < L+n ; R++) {
                    int temp[n] = {0};
                    int local_ans = INT_MIN;
                    //cout << "t == " << t << " L == " << L << " R == " << R << endl;
                    for(int i = t ; i < t+n ; i++) {
                        max1D[i-t] += grid[i][R];
                        if(i > t) {
                            if(temp[i-1-t] < 0) {
                                temp[i-t] = max1D[i-t];
                            }else{
                                temp[i-t] = temp[i-1-t] + max1D[i-t];
                            }
                        }else{
                            temp[i-t] = max1D[i-t];
                        }
                        //cout << "Max1D[" << i << "] == " << max1D[i-t] << endl;
                        local_ans = max(local_ans, temp[i-t]);
                    }
                    //cout << "local_ans == " << local_ans << endl << endl << endl;
                    ans = max(local_ans, ans);
                }
            }
        }



        cout << ans << endl;

    }
}

