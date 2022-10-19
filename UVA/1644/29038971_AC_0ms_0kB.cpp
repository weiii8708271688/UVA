#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

vector <int> prime;

bool isprime[1300000] = {1, 0, 1};
void prime_() {
    prime.push_back(2);
    for(int i = 3 ; i < 1300000 ; i+=2) {
        isprime[i] = true;
    }
    for(int i = 3 ; i < 1300000 ; i+=2) {
        if(isprime[i]) {
            prime.push_back(i);
            for(int j = i+i ; j < 1300000 ; j+=i) {
                isprime[j] = false;
            }
        }
    }
}

int main(){
    prime_();
    int Size = prime.size();
    long long n;
    while(cin >> n) {
        if(!n) break;
        if(isprime[n]) cout << 0 <<endl;
        else{
            long long up, down;
            for(int i = n ; i < 1300000 ; i++) {
                if(isprime[i]) {
                    up = i;
                    break;
                }
            }
            for(int i = n ; i >= 0 ; i--) {
                if(isprime[i]) {
                    down = i;
                    break;
                }
            }
            cout << up-down << endl;
        }
    }
}
