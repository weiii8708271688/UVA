#include<iostream>
#include<cmath>
using namespace std ;

int coin[5] = {1,5,10,25,50};


int main(){
    int ans[7500] = {1};
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = coin[i] ; j < 7500 ; j++) {
            ans[j] += ans[j-coin[i]];
        }
    }
    int n;
    while(cin >> n) {
        cout << ans[n] << endl;
    }
}
