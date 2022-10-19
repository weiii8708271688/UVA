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

vector <string> ans;
string s1, s2;

void dfs(vector<char> ans, int pos, string output, stack<char> inside) {

    for(int i = 0 ; i < output.size() ; i++) {
        if(output[i] != s2[i]) return;
    }
    if(ans.size() == s1.size()*2) {
        if(output == s2) {
            for(int i = 0 ; i < ans.size() ; i++) {
                cout << ans[i];
                if(i != ans.size()-1) cout << " ";
            }
            cout << endl;
        }
        return;
    }

    if(pos < s1.size()) {
        ans.push_back('i');
        inside.push(s1[pos]);
        dfs(ans, pos+1, output, inside);
        ans.pop_back();
        inside.pop();
        if(!inside.empty()) {
            ans.push_back('o');
            output += inside.top();
            inside.pop();
            dfs(ans, pos, output, inside);
        }
    }else{
        ans.push_back('o');
        output += inside.top();
        inside.pop();
        dfs(ans, pos, output, inside);
    }


}



int main() {
    while(cin >> s1) {
        cin >> s2;
        queue <char> after;
        vector <char> ans;
        stack <char> inside;
        cout << "[" << endl;
        if(s1.size() != s2.size()) {
            cout << "]" << endl;
            continue;
        }
        dfs(ans, 0, "", inside);
        cout << "]" << endl;
    }
}
