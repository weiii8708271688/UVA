#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <limits.h>
using namespace std;

int ans[101];
vector <int> node[101];
queue <int> q;



void bfs() {
    while(!q.empty()) {
        int b = q.front(); q.pop();
        for(int i = 0 ; i < node[b].size() ; i++) {
            int c = node[b][i];
            if(ans[b]+1 >= ans[c]) {
                ans[c] = ans[b]+1;
                q.push(c);
            }
        }
    }

}



int main() {
    int n, c = 1;
    while(cin >> n) {
        if(!n) break;
        int snode;
        cin >> snode;
        for(int i = 0 ; i < n+1 ; i++) {
            ans[i] = -1;
            node[i].clear();
        }
        ans[snode] = 0;
        while(true) {
            int a, b;
            cin >> a >> b;
            if(!a && !b) break;
            node[a].push_back(b);
        }
        q.push(snode);
        bfs();
        int output = -1;
        int enode = -1;
        for(int i = 1 ; i <= n  ; i++) {
            if(ans[i] > output) {
                output = ans[i];
                enode = i;
            }
        }
        cout << "Case " << c++ << ": The longest path from " << snode << " has length " << ans[enode] << ", finishing at " << enode <<"." << endl << endl;
    }
}


