#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;



int main(){
    int ans[21] = {0};
    ans[2] = 1;
    ans[4] = 2;
    int n;
    for(int i = 6 ; i < 21 ; i+=2) {
        ans[i] = ans[i-2]*2;
        for(int j = 2 ; j < i-2 ; j+=2) {
            ans[i] += ans[j]*ans[i-j-2];
        }
    }
    bool firstdone = false;
    while(cin >> n) {
        n*=2;
        if(firstdone)cout << endl;
        else firstdone = true;
        cout << ans[n] << endl;
    }
}
