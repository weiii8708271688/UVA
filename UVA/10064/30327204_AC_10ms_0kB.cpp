#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

bool cmp(double a, double b){
    return a > b;
}

int main() {
    int n;
    while(cin >> n) {
        double fri[n];
        double sum = 0;
        for(int i = 0 ; i < n ; i++) {
            cin >> fri[i];
            sum+=fri[i];
        }
        sum/=n;
        sort(fri, fri+n, cmp);
        if(!n)
            cout << -1 << endl;
        else
            cout << fixed << setprecision(2) << sum << " " <<  fri[n/2] << endl;
    }
}
