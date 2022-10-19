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


void DFS(bool *pass, vector <int> *vertex, int v) {
    pass[v] = true;
    for(int i = 0 ; i < vertex[v].size() ; i++) {
        if(!pass[vertex[v][i]]) {
            DFS(pass, vertex, vertex[v][i]);
        }
    }
}


int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        vector <int> vertex[n+1];
        int s;
        while(cin >> s) {
            if(!s) break;
            int e;
            while(cin >> e) {
                if(!e) break;
                vertex[s].push_back(e);
            }
        }
        int nums;
        cin >> nums;
        while(nums--) {
            cin >> s;
            bool pass[n+1] = {0};
            for(int i = 0 ; i < vertex[s].size() ; i++) {
                DFS(pass, vertex, vertex[s][i]);
            }
            vector<int> ans;
            for(int i = 1 ; i <= n ; i++) {
                if(!pass[i]) ans.push_back(i);
            }
            if(ans.empty()) cout << "0" << endl;
            else {
                cout << ans.size();
                for(int i = 0 ; i < ans.size() ; i++) {
                    cout << " " << ans[i];
                }
                cout << endl;
            }
        }
    }
}
