#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        map<string, int> count;
        while(n--) {
            string s[5];
            for(int i = 0 ; i < 5; i++) {
                cin >> s[i];
            }
            sort(s, s+5);
            string s2 = "";
            for(int i = 0 ; i < 5; i++) {
                s2 += s[i];
            }
            count[s2]++;
        }
        int max = 0;
        map<string, int>::iterator it;
        int ans = 0;
        for(it = count.begin() ; it != count.end() ; it++) {
            if(it->second > max) {
                max = it->second;
                ans = 0;
            }
            if(it->second == max) {
                ans += it->second;
            }
        }
        cout << ans << endl;
    }
}
