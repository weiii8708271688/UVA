#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

bool isprime[70000] = {0};

void prime_() {
    for(int i = 0 ; i < 70000 ; i++) {
        isprime[i] = false;
    }
    for(int i = 3 ; i < 70000 ; i+=2) {
        isprime[i] = true;
    }
    for(int i = 3 ; i < 70000 ; i+=2) {
        if(isprime[i]) {
            for(int j = i+i ; j < 70000 ; j+=i) {
                isprime[j] = false;
            }
        }
    }
}

long long mod(long long a, long long n, long long orin) {
    if(n == 0) return 1;
    if(n == 1) return a;
    long long ans = mod(a, n/2, orin);
    if(n%2 == 0) {
        return (ans*ans)%orin;
    }else{
        return (((ans*ans)%orin)*a)%orin;
    }
}


int main() {
    int n;
    prime_();
    while(cin >> n) {
        if(!n) break;
        bool check = true;
        if(isprime[n]) {
            cout << n << " is normal." << endl;
            continue;
        }
        for(int i = 2 ; i < n ; i++) {
            long long ans = mod(i,n,n);
            //cout << i << " remain == " << ans << endl;
            if(ans != i) {
                check = false;
                break;
            }
        }
        if(!check) {
            cout << n << " is normal." << endl;
        }else{
            cout << "The number " << n << " is a Carmichael number." << endl;
        }
    }
}
