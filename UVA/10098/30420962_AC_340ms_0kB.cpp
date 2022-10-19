#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << endl;
        while(next_permutation(s.begin(), s.end())) {
            cout << s << endl;
        }
        cout << endl;
    }
}
