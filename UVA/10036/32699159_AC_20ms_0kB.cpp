#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;


int main() {
    int n;
    cin >> n;
    while(n--) {
        int m, k, sum = 0;
        cin >> m >> k;
        int num[m];
        for(int i = 0 ; i < m ; i++) {
            cin >> num[i];
            num[i] = abs(num[i]);
            num[i]%=k;
            sum+=num[i];
        }
        bool valid[k*m] = {0};
        valid[0] = true;
        for(int i = 0 ; i < m ; i++) {
            vector <int> pass;
            for(int j = 0 ; j < 100 ; j++) {
                if(valid[j] && !valid[j+num[i]] && j+num[i] < k*m) {
                    pass.push_back(j+num[i]);
                }
            }
            for(int j = 0 ; j < pass.size() ; j++) {
                valid[pass[j]] = true;
            }
        }
        bool pass = false;
        if(!sum || (sum %2 == 0 && valid[sum/2]) ) pass = true;
        int temp = sum - sum/k*k;
        for(int i = 0 ; i < sum/k ; i++) {
            if(temp > k*m*2) break;
            if(temp%2 == 0 && valid[temp/2]) {
                pass = true;
                break;
            }
            temp += k;
        }
        if(pass) {
            cout << "Divisible" << endl;
        }else{
            cout << "Not divisible" << endl;
        }

    }
}
