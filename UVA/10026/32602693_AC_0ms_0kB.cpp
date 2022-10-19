#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int c;
        cin >> c;
        int d[c], p[c];
        for(int i = 0 ; i < c ; i++) {
            cin >> d[i] >> p[i];
        }
        long long ans_p = p[0], ans_d = d[0];
        vector <int> ans;
        ans.push_back(0);
        for(int i = 1 ; i < c ; i++) {
            long long add = ans_p * d[i]
;           int sert = 0;
            long long temp_p = ans_p, temp_d = 0;
            for(int j = 1 ; j < ans.size()+1 ; j++) {
                int l = ans[j-1];
                temp_d += d[l];
                temp_p -= p[l];
                if(d[i]*temp_p + temp_d*p[i] <= add) {
                    add = d[i]*temp_p + temp_d*p[i];
                    sert = j;
                }
            }
            ans_d += d[i];
            ans_p += p[i];
            ans.insert(ans.begin()+sert, i);
        }
        for(int i = 0 ; i < c ; i++) {
            cout << ans[i]+1;
            if(i < c-1) cout << " ";
        }
        cout << endl;
        if(n) cout << endl;
    }
}


