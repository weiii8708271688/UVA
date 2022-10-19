#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int fib(int n, int *result) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(result[n]) return result[n];
    result[n] = fib(n-1, result) + fib(n-2, result);
    return result[n];
}



int main(){
    int n,temp;
    char ch;
    string ans[5001];
    ans[0] = "0";
    ans[1] = "1";
    for(int i = 2 ; i < 5001 ; i++) {
        string s1 = "", s2 = ans[i-1], tempans = "";
        tempans+='0';
        if(ans[i-2].size() != s2.size()) {
            temp = s2.size() - ans[i-2].size();
            for(int j = temp ; j > 0 ; j--) {
                s1+='0';
            }
        }
        s1+=ans[i-2];
        //cout << "ans " << i-2 << " == " << s1 << " ans " << i-1 << "=="  << s2 << endl << endl;
        for(int j = 0 ; j < s2.size() ; j++) {
            temp = s1[j]+s2[j]-2*'0';
            if(temp >= 10) {
                temp-=10;
                int k = 0;
                tempans[j]++;
                ch = temp+'0';
                tempans+=ch;
                while(tempans[j+k] > '9') {
                    temp = tempans[j+k] - '0';
                    temp-=10;
                    ch = temp+'0';
                    tempans[j+k] = ch;
                    tempans[j+k-1]++;
                    k--;
                }
            }else{
                ch = temp + '0';
                tempans+=ch;
            }
        }
        if(tempans[0] == '0') {
            tempans.erase(0, 1);
        }
        ans[i] = tempans;
    }
    while(cin >> n) {
        cout << "The Fibonacci number for " << n << " is " << ans[n] <<endl;
    }
}
