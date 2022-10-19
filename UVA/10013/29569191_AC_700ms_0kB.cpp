#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;



int main() {
    int c,m,num1,num2;
    cin >> c;
    while(c--) {
        cin >> m;
        int ans[m+1] = {0};
        for(int i = 1 ; i < m+1 ; i++) {
            cin >> num1 >> num2;
            ans[i] = num1 + num2;
        }
        for(int i = m ; i > 0 ; i--) {
            if(ans[i] >= 10) {
                ans[i-1]+=ans[i]/10;
                ans[i]%=10;
            }
        }
        int i;
        if(ans[0]) {
            i = 0;
        }else{
            i = 1;
        }
        for(;i < m+1 ; i++) {
            cout << ans[i];
        }
        cout << endl;
        if(c) cout << endl;
    }
}
