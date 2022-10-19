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
    while(cin >> n) {
        if(!n) break;
        string s;
        cin >> s;
        int temp = s.size()/n;
        for(int i = 0 ; i < n ; i++) {
            reverse(s.begin()+i*temp,s.begin()+(i+1)*temp);
        }
        cout << s << endl;
    }
}
