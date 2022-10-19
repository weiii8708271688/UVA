#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <climits>
using namespace std;
int ans[20001];
vector <vector<pair<int, int>>> G;

struct coor{
    int x, w;
    bool operator> (const coor& a) const{
        return a.w < w;
    }
};
vector <coor> edge;


int bfs(int S, int T) {
    priority_queue<coor, vector<coor>, greater<coor>> pq;
    coor tmp;
    tmp.x = S;
    tmp.w = 0;
    ans[S] = 0;
    pq.push(tmp);
    while(!pq.empty()) {
        tmp = pq.top(); pq.pop();
        if(tmp.x == T) return tmp.w;
        for(auto v: G[tmp.x]) {
            if(ans[v.first] == -1 || ans[v.first] > tmp.w + v.second) {
                ans[v.first] = tmp.w + v.second;
                coor tmp2;
                tmp2.x = v.first;
                tmp2.w = ans[v.first];
                pq.push(tmp2);
            }
        }
    }
    return -1;
}


int main() {
    int N, t = 1;
    cin >> N;
    while(N--) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        G.assign(n, vector<pair<int, int>>());
        for(int i = 0 ; i < n ; i++) ans[i] = -1;
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(make_pair(b,c));
            G[b].push_back(make_pair(a,c));
        }
        int output = bfs(S, T);
        cout << "Case #" << t++ << ": ";
        if(output != -1) cout << output << endl;
        else cout << "unreachable" << endl;
    }


}
