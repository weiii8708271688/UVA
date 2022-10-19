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
int ans[101];
vector <vector<pair<int, int>>> G;

struct coor{
    int x, w;
    bool operator> (const coor& a) const{
        return a.w < w;
    }
};
vector <coor> edge;


int bfs(int T, int E) {
    priority_queue <coor, vector<coor>, greater<coor>> pq;
    int ret = 0;
    coor tmp;
    tmp.x = E;
    tmp.w = 0;
    ans[E] = 0;
    pq.push(tmp);
    while(!pq.empty()) {
        coor now_coor = pq.top(); pq.pop();
        if(now_coor.w > T) return ret;
        else ret++;
        int now = now_coor.x;
        for(auto v: G[now]) {
            if(ans[v.first] == -1 || ans[v.first] > ans[now] + v.second) {
                ans[v.first] = ans[now] + v.second;
                tmp.x = v.first;
                tmp.w = ans[v.first];
                pq.push(tmp);
            }
        }
    }
    return ret;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, E, T, M;
        cin >> N >> E >> T >> M;
        G.assign(N+1, vector<pair<int, int>>());
        edge.clear();
        while(M--) {
            int a, b, c;
            cin >> a >> b >> c;
            G[b].push_back(make_pair(a, c));
        }
        for(int i = 0 ; i <= N ; i++) ans[i] = -1;
        cout << bfs(T, E) << endl;
        if(t) cout << endl;
    }


}
