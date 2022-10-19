#include <bits/stdc++.h>
using namespace std;


int main() {
    long long ans[30001] = {1};
    long long d[5] = {1, 5, 10, 25, 50};
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = d[i] ; j < 30001 ; j++) {
            ans[j] += ans[j-d[i]];
        }
    }

    int n;
    while(cin >> n) {
        if(ans[n] == 1) {
            cout << "There is only " << ans[n] << " way to produce " << n << " cents change." << endl;
        }else{
            cout << "There are " << ans[n] << " ways to produce " << n << " cents change." << endl;
        }
    }
}
