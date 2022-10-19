#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;



int main(){
    long long ans[20000001] = {0};
    for(int i = 1 ; i < 20000001 ; i++) {
        for(int j = i ; j < 20000001 ; j+=i) {
            ans[j]+=i;
        }
    }
    ans[1] = 0;
    for(int i = 1 ; i < 20000001 ; i++) {
        ans[i] += ans[i-1];
    }
    long long n;
    while(cin >> n) {
        if(!n) break;
        cout << ans[n] << endl;
    }
}
