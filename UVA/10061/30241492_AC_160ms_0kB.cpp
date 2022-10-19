#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int n,b;
    while(cin >> n >> b) {
        double logOfb = log10(b) ,digit = 0;
        int bcount[b+1] = {0};
        int ncount[b+1] = {0};
        for(int temp = b, j = 2 ; j <= b ; j++) {
            while(temp%j == 0) {
                bcount[j]++;
                temp/=j;
            }
        }
        for(int i = 2 ; i <= n ; i++) {
            digit += (log10(i) / logOfb);
            for(int temp = i, j = 2 ; j <= b ; j++) {
                while(temp%j == 0) {
                    ncount[j]++;
                    temp/=j;
                }
            }
        }
        int ans = digit+1;
        for(int i = 0 ; i < b+1 ; i++) {
            if(bcount[i]) {
                int temp = ncount[i]/bcount[i];
                if(temp < ans) {
                    ans = temp;
                }
            }
        }
        cout << ans << " " << (int)digit+1 << endl;
    }
}
