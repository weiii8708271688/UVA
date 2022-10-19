#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
vector <int> prime;

bool check[1000] = {0,0,1,1};
void primetry() {
    for(int i = 3 ; i < 1000 ; i+=2) {
        check[i] = true;
    }
    for(int i = 3 ; i < 1000 ; i+=2) {
        if(check[i]) {
            for(int j = i+i ; j < 1000 ; j+=i) {
                check[j] = false;
            }
        }
    }
    for(int i = 0 ; i < 1000 ; i++) {
        if(check[i]) {
            prime.push_back(i);
        }
    }
}


int main(){
    int n;
    int max = 0;
    int ansnum = 0;
    primetry();
    int *primecout = new int [1000001];
    int Size = prime.size();
    primecout[0] = 0;
    primecout[1] = 1;
    for(int k = 2; k <= 1000000 ; k++) {
        int primecount[Size] = {0};
        int temp = k;
        int i;
        while(temp!=1) {
            for(i = 0 ; i < Size ; i++) {
                if(temp % prime[i] == 0) {
                    temp/=prime[i];
                    primecount[i]++;
                    break;
                }
            }
            if(i == Size) break;
        }
        if(temp==1){
            for(int i = 0 ; i < Size ; i++) {
                if(primecount[i])
                    temp*=(primecount[i]+1);
            }
            if(temp >= max) {
                max = temp;
                ansnum = k;
            }
        }
        primecout[k] = ansnum;
    }
    cin >> n;
    while(n--) {
        int k;
        cin >> k;
        int ans = 0, ansnum;
        cout << primecout[k] <<endl;
    }
}
