#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    long long n;
    int casenum;
    cin >> casenum;
    while(casenum--) {
        cin >> n;
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }else if(n == 0) {
            cout << 0 << endl;
            continue;
        }
        int count[10] = {0};
        for(int i = 9 ; i > 1 ; i--) {
            while(n%i == 0) {
                n/=i;
                count[i]++;
            }
        }
        if(n==1) {
            for(int i = 2 ; i < 10 ; i++) {
                while(count[i]) {
                    count[i]--;
                    cout << i;
                }
            }
        }else{
            cout << -1;
        }
        cout << endl;
    }
}
