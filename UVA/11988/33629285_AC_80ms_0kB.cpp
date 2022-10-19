#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
using namespace std;


int main() {
    string s;
    while(cin >> s) {
        deque<string> ans;
        string temp = "";
        char last = ']';
        for(int i = 0 ; i <= s.size() ; i++) {
            if(s[i] == '[' || s[i] == ']' || i == s.size()) {
                if(last == '[') {
                    ans.push_front(temp);
                }else if(last == ']') {
                    ans.push_back(temp);
                }
                if(i != s.size())last = s[i];
                temp = "";
            }else{
                temp += s[i];
            }
        }
        for(int i  =0 ; i < ans.size() ; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
}
