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
bool pass[50000];

int DFS(bool* visited, int* v, int curr, int ans) {
    pass[curr] = visited[curr] = true;
    if(!visited[v[curr]]) {
        return DFS(visited, v, v[curr], ans+1);
    }
    return ans;
}


int main() {
    int c, t = 1;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        int v[n+1];
        for(int i = 1 ; i <= n ; i++) {
            int a, b;
            cin >> a >> b;
            v[a] = b;
            pass[i] = false;
        }
        int ans = 0, maxx = -1;
        for(int i = 1 ; i <= n ; i++) {
            if(!pass[i]) {
                bool visited[n+1] = {0};
                int temp = DFS(visited, v, i, 1);
                if(temp > maxx) {
                    maxx = temp;
                    ans = i;
                }
            }
        }

        cout << "Case " << t++ << ": " << ans << endl;
    }
}
