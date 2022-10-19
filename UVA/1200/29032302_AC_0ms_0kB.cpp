#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    int n;
    string s;
    cin >> n;
    getline(cin,s);
    while(n--) {
        getline(cin, s);
        int x[2] = {0}, num[2] = {0};
        int now = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == 'x') {
                if(i-1>=0) {
                    if(s[i-1] == '-') {
                        x[now]--;
                    }else{
                        x[now]++;
                    }
                }else{
                    x[now]++;
                }
            }
            if(isalnum(s[i])) {
                int temp = 0;
                int sign = 1;
                if(s[i-1] == '-') sign = -1;
                while(isdigit(s[i])) {
                    temp = temp*10 + (s[i] - '0');
                    i++;
                }
                temp*=sign;
                if(s[i] == 'x') {
                    x[now]+=temp;
                }else{
                    num[now]+=temp;
                }
            }
            if(s[i] == '=') now = 1;
        }
        int ans[2];
        ans[0] = x[0]-x[1];
        ans[1] = num[1]-num[0];
        if(ans[0]) {
            if(ans[0] * ans[1] < 0 && ans[1] % ans[0]) {
                cout << ans[1]/ans[0]-1 << endl;
            }else{
                cout << ans[1]/ans[0] << endl;
            }
        }else{
            if(ans[1]) {
                cout << "IMPOSSIBLE" << endl;
            }else{
                cout << "IDENTITY" << endl;
            }
        }
    }
}
