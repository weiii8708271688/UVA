#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

vector<int> prime;
bool isprime[35000] = {0};
void prime_() {
    prime.push_back(2);
    for(int i = 3 ; i < 35000 ; i+=2) {
        isprime[i] = true;
    }
    for(int i = 3 ; i < 35000 ; i+=2) {
        if(isprime[i]) {
            prime.push_back(i);
            for(int j = i+i ; j < 35000 ; j+=i) {
                isprime[j] = false;
            }
        }
    }
}

int main() {
    prime_();
    int n;
    while(cin >> n) {
        if(!n) break;
        int ans = 0;
        for(int i = 2 ; i <= n ; i++) {
            ans = (ans+prime[n-i])%i;
        }
        cout << ans+1 << endl;
    }
}
