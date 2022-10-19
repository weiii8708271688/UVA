#include <vector>
#include<iostream>
#include<cmath>
using namespace std ;

bool check[40000] = {0,0,1};
vector <int> prime;
void prime_() {
    for(int i = 3 ; i < 40000 ; i+=2) {
        check[i] = true;
    }
    prime.push_back(2);
    for(int i = 3 ; i < 40000 ; i+=2) {
        if(check[i]) {
            prime.push_back(i);
            for(int j = i+i ; j < 40000 ; j+=i) {
                check[j] = false;
            }
        }
    }
}

int main(){
    prime_();
    int Size = prime.size();
    int n;
    int ans[40000] = {0};
    for(int i = 0 ; i < Size ; i++) {
        for(int j = i ; j < Size ; j++) {
            int temp = prime[i]+prime[j];
            if(temp < 40000) {
                ans[temp]++;
            }else{
                break;
            }
        }
    }
    while(cin >> n){
        if(!n) break;
        cout << ans[n] << endl;
    }
}
