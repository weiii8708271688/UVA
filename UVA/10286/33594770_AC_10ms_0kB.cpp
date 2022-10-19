#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    double n;
    double PI = acos(-1.0);
    while(cin >> n) {
        cout << fixed << setprecision(10) <<  n/sin(63.0*PI/180.0)*sin(108.0*PI/180.0) << endl;
    }
}
