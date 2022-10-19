#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(!n) {
            cout << "0" << endl;
            continue;
        }
        vector <int> tail, num;
        num.assign(n*2, -1);
        tail.assign(n, -1);
        for(int i = 0 ; i < n ; i++) {
            cin >> num[i+n];
            num[n-i-1] = num[i+n];
        }
        int length = 0;
        tail[0] = num[0];
        for(int i = 1 ; i < num.size() ; i++) {
            if(num[i] < tail[0]) {
                tail[0] = num[i];
            }else if(num[i] > tail[length]) {
                tail[++length] = num[i];
            }else{
                for(int j = 0 ; j <= length ; j++) {
                    if(num[i] <= tail[j]) {
                        tail[j] = num[i];
                        break;
                    }
                }
            }
        }
        
        cout << length+1 << endl;
    }
}

