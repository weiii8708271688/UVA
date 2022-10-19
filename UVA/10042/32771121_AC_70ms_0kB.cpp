#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

bool* primecheck = new bool[50000]();
vector <int> prime;
vector <int> smith;

void prime_() {
    prime.push_back(2);
    for(int i = 3 ; i < 50000 ; i+=2) {
        if(!primecheck[i]) {
            prime.push_back(i);
            for(int j = i+i ; j < 50000 ; j+=i) {
                primecheck[j] = true;
            }
        }
    }
}

int add_digit(int a) {
    int ans = 0;
    while(a) {
        ans += a%10;
        a/=10;
    }
    return ans;
}

void smith_(int a) {
    while(a++) {
        int ans = add_digit(a), test = 0, temp = a, count = 0;
        for(int j = 0 ; j < prime.size() ; j++) {
            while(temp % prime[j] == 0) {
                test += add_digit(prime[j]);
                temp/=prime[j];
                count++;
            }
        }
        if(temp != 1) {
            test += add_digit(temp);
            count++;
        }
        if(count == 1) {
            continue;
        }
        if(ans == test) {
            cout << a << endl;
            return;
        }
    }
}




int main() {
     prime_();

     int n;
     cin >> n;
     while(n--) {
        int s;
        cin >> s;
        smith_(s);
     }
     delete []primecheck;
}
