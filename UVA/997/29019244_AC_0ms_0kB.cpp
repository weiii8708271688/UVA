#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    string s;
    int n;
    while(cin >> s) {
        vector <int> num;
        vector <char> oper;
        cin >> n;
        int count = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '+' || s[i] == '*') {
                oper.push_back(s[i]);
            }else if(isalnum(s[i])) {
                bool re = false;
                if(s[i-1] == '-') re = true;
                int temp = s[i]-'0';
                i++;
                while(isalnum(s[i])) {
                    temp = temp*10 + s[i]-'0';
                    i++;
                }
                i--;
                if(re) temp *= -1;
                num.push_back(temp);
            }else if(s[i] == ']') {
                count++;
            }
        }
        int ans[count][n] = {0};
        for(int i = 0 ; i < n ; i++) {
            ans[count-1][i] = num[count-1];
        }
        for(int i = 0 ; i < count ; i++) {
            ans[i][0] = num[i];
        }
        for(int i = count-2  ; i >= 0 ; i--) {
            if(oper[i] == '+') {
                for(int j = 1 ; j < n ; j++) {
                    ans[i][j] = ans[i][j-1] + ans[i+1][j-1];
                }
            }else if(oper[i] == '*') {
                ans[i][0] = num[i]*ans[i+1][0];
                for(int j = 1 ; j < n ; j++) {
                    ans[i][j] = ans[i][j-1] * ans[i+1][j];
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            cout << ans[0][i];
            if(i != n-1) cout << " ";
        }
        cout << endl;
    }
}
