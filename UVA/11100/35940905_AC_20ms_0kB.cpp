#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        int backpack[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> backpack[i];
        }
        sort(backpack, backpack+n);
        int num = 0;
        for(int i = 0 ; i < n ; i++) {
            int temp = 1;
            while(backpack[i] == backpack[i+1] && i+1 < n) {
                temp++;
                i++;
            }
            num = max(temp, num);
        }
        cout << num << endl;
        for(int i = 0 ; i < num ; i++) {
            for(int j = i ; j < n ; j+=num) {
                if(j!=i) cout << " ";
                cout << backpack[j];
            }
            cout << endl;
        }
        cout << endl;
    }
}
