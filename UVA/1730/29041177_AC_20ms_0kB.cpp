#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

// not me
int main()
{
    int n;
    while (cin >> n)
    {
        if(!n) break;
        long long ans = 0, times, R, L = 1;
        while (L <= n){
            times = n / L;
            R = n / times;
            ans += times * ((L + R) * (R - L + 1) / 2); //梯形公式
            L = R + 1;
        }
        cout << ans-1 << endl;
    }

    return 0;
}
