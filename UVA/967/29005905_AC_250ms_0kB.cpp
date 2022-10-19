#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

bool prime[1000001] = {0};


void prime_() {
    prime[2] = true;
    for(int i = 3 ; i < 1000001 ; i+=2) {
        prime[i] = true;
    }
    for(int i = 3 ; i < 1000001 ; i+=2) {
        if(prime[i]) {
            for(int j = i+i ; j < 1000001 ; j+=i) {
                prime[j] = false;
            }
        }
    }
}

int main(){
    prime_();
    int top, down;
    int ans[1000001] = {0};
    int max = 0;
    for(int i = 100 ; i <= 1000000 ; i++) {
            int count = 1, temp = i;
            while(temp / 10) {
                count++;
                temp/=10;
            }
            temp = i;
            bool iscir = true;
            for(int j = 0 ; j < count ; j++) {
                if(!prime[temp]) {
                    iscir = false;
                    break;
                }
                temp = pow(10,count-1)*(temp%10) + temp/10;
            }
            if(iscir) max++;
            ans[i] = max;
        }
    while(cin >> down) {
        if(down == -1) break;
        cin >> top;
        int ansnum = ans[top] - ans[down-1];
        if(ansnum == 0) {
            cout << "No Circular Primes." << endl;
        }else if(ansnum == 1) {
            cout << "1 Circular Prime." << endl;
        }else{
            cout << ansnum << " Circular Primes." << endl;
        }
    }
}
