#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

bool prime[1001] = {0,1};

void prime_(bool prime[]) {

}


int main(){
    bool prime[1001] = {0,1,1};
    for(int i = 2 ; i <= 1000 ; i++) {
        prime[i] = true;
    }
    for(int i = 3 ; i <= 1000 ; i++) {
        if( !(i%2) ) prime[i] = false;
        if(prime[i]) {
            for(int j = i ; j < 1000 ; j++) {
                int temp = i*j;
                if(temp <= 1000)
                    prime[temp] = false;
            }
        }
    }
    int n;
    int c;
    while(cin >> n >> c) {
        cout << n << " " << c << ": ";
        vector <int> ans;
        for(int i = 0 ; i <= n ; i++) {
            if(prime[i]) {
                ans.push_back(i);
            }
        }
        int temp = ans.size();
        bool largec = false;
        if(temp%2) {
            if(c*2 + 1 > temp) largec = true;
        }else{
            if(c*2 > temp) largec = true;
        }

        if(largec) {
            for(int i = 0 ; i < temp ; i++) {
                if(i!=0) cout << " ";
                cout << ans[i];
            }
        }else{
            if(temp%2) {
                temp/=2;
                for(int i = -c+1 ; i < c ; i++) {
                    if(i!=-c+1) cout << " ";
                    cout << ans[temp+i];
                }
            }else{
                temp/=2;
                for(int i = -c ; i < c ; i++) {
                    if(i!=-c) cout << " ";
                    cout << ans[temp+i];
                }
            }
        }
        cout << endl << endl;
        ans.clear();
    }
}
