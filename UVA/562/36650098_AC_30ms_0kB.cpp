#include<bits/stdc++.h>

using namespace std;







int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int coin[n];
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            cin >> coin[i];
            sum += coin[i];
        }
        vector<vector<bool> >dp;
        vector<bool> canget;
        canget.assign(sum+1, false);
        canget[0] = true;
        for(int t = 0 ; t < n ; t++) {
            for(int i = sum ; i >= coin[t] ; i--) {
                if(canget[i-coin[t]]) canget[i] = true;
            }
        }
        int mid = sum/2;


        int ansl = INT_MAX;
        int ansr = INT_MAX;

        for(int i = mid ; i <= sum ; i++) {
            if(canget[i]){
                ansl = abs(i-(sum-i));
                break;
            }
        }

        for(int i = mid ; i >= 0 ; i--) {
            if(canget[i]){
                ansr = abs(i-(sum-i));
                break;
            }
        }




        cout << min(ansl, ansr) << endl;

    }
}
