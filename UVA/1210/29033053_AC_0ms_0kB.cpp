#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

vector <int> prime;

bool isprime[10001];

void prime_() {
    for(int i = 3 ; i < 10001 ; i+=2) {
        isprime[i] = true;
    }
    prime.push_back(2);
    for(int i = 3 ; i < 10001 ; i+=2) {
        if(isprime[i]) {
            prime.push_back(i);
            for(int j = i+i ; j < 10001 ; j+=i) {
                isprime[j] = false;
            }
        }
    }
}


int main(){
    prime_();
    int Size = prime.size();
    int ans[10001] = {0};
    for(int i = 0 ; i < Size ; i++) {
        int temp = 0;
        for(int j = i ; j < Size ; j++) {
            temp+=prime[j];
            if(temp < 10001)
            ans[temp]++;
        }
    }
    int n;
    while(cin >> n) {
        if(!n) break;
        cout << ans[n] << endl;
    }
}
