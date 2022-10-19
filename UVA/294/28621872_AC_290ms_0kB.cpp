#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


int getcount(long long n) {
    int ans = 0;
    for(int i = 1 ; i <= sqrt(n) ; i++) {
        if(n % i == 0) {
            if(n / i == i) {
                ans++;
            }
            else{
                ans+=2;
            }
        }
    }
    return ans;
}

int main() {
	int n;
	cin >> n;
	while(n--) {
        long long maxnum;
        long long maxx = 0;
        long long up, low;
        cin >> low >> up;
        cout << "Between "<< low  << " and " << up << ", ";
        for(; low <= up ; low++) {
            long long temp = getcount(low);
            if(temp > maxx) {
                maxx = temp;
                maxnum = low;
            }
        }
        cout << maxnum << " has a maximum of "<< maxx << " divisors." << endl;
	}
}
