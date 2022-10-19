#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, t = 1;
    cin >> T;
    while(T--) {
        cin >> n;
        int ansLIS, ansLDS;
        ansLIS = ansLDS = 0;
        vector <int> LIS, num, LDS, l, w;
        w.assign(n, -1);
        l.assign(n, -1);
        LDS.assign(n, -1);
        LIS.assign(n, -1);
        for(int i = 0 ;i < n ; i++) {
            cin >> l[i];
        }
        for(int i = 0 ; i < n ; i++) {
            cin >> w[i];
        }
        for(int i = 0 ; i < n ; i++) {
            LDS[i] = LIS[i] = w[i];
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(l[i] > l[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + w[i]);
                }
                if(l[i] < l[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + w[i]);
                }
            }
            ansLIS = max(ansLIS, LIS[i]);
            ansLDS = max(ansLDS, LDS[i]);
        }
        cout << "Case " << t++ << ". ";
        if(ansLDS > ansLIS) {
            cout << "Decreasing (" << ansLDS << "). Increasing (" << ansLIS << ")." << endl;
        }else{
            cout << "Increasing (" << ansLIS << "). Decreasing (" << ansLDS << ")." << endl;
        }
    }
}

