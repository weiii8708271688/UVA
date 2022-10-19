#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

bool isprime[32800];

void prime() {
    for(int i = 0 ; i < 32800 ; i++) {
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    isprime[2] = true;
    for(int i = 3 ; i < 32800 ; i++) {
        if(i%2 == 0) isprime[i] = false;
        if(isprime[i]) {
            for(int j = i+i ; j < 32800 ; j+=i) {
                isprime[j] = false;
            }
        }
    }
}


int main() {
    prime();
    int num;
    int pownum;
    int ans;
    string s;
    while(getline(cin, s)) {
        int primecount[32800] = {0};
        ans = 1;
        bool state = true;
        if(s == "0") break;
        for(int i = 0 ; i < s.size() ; i++) {
            if(isalnum(s[i])) {
                if(state) {
                    num = 0;
                    while(isalnum(s[i])) {
                        num = num*10 + s[i] - '0';
                        i++;
                        state = false;
                    }
                }else{
                    pownum = 0;
                    while(isalnum(s[i])) {
                        pownum = pownum*10 + s[i] - '0';
                        i++;
                    }
                    ans*=pow(num, pownum);
                    state = true;
                }
            }
        }
        ans--;
        while(ans != 1) {
            for(int i = 1 ; i < 32800 ; i++) {
                if(isprime[i]) {
                    if(ans % i == 0) {
                        ans/=i;
                        primecount[i]++;
                    }
                }
            }
        }
        bool bottom = true;
        for(int i = 32799 ; i > 0 ; i--) {
            if(primecount[i]) {
                if(bottom) {
                    bottom = false;
                }else
                    cout << " ";
                cout << i << " " << primecount[i];
            }
        }
        cout << endl;
    }
}

