#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

int main() {
    string contin;
    int c = 1;
    while(cin >> contin) {
        if(contin == "end") break;
        vector<stack<int>> s;
        s.clear();
        for(int i = 0 ; i < contin.size() ; i++) {
            bool need = true;
            for(int j = 0 ; j < s.size() ; j++) {
                if(contin[i] <= s[j].top()) {
                    s[j].push(contin[i]);
                    need = false;
                    break;
                }
            }
            if(need) {
                stack<int> temp;
                temp.push(contin[i]);
                s.push_back(temp);
            }
        }
        cout << "Case " << c++ << ": "<< s.size() << endl;

    }
}
