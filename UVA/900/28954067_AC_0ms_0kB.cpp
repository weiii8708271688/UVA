#include <vector>
#include<iostream>
#include<cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;



int main(){
    int n;
    long long ans[51] = {0,1,2,3};
    for(int i = 4 ; i < 51 ; i++) {
        ans[i] = ans[i-1]+ans[i-2];
    }
    while(cin >> n) {
        if(!n) break;
        cout << ans[n] << endl;
    }
}
