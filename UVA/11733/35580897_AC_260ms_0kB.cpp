#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
using namespace std;


struct Edge{
    int from, to, cost;
    Edge(int a, int b, int c) {
        from = a;
        to = b;
        cost = c;
    }
};

vector <Edge> edges;
vector <int> p;
int find_parent(int x) {
    if(p[x] != x) {
        p[x] = find_parent(p[x]);
    }
    return p[x];
}

bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

int main() {
    int T, t = 1;
    cin >> T;
    while(T--) {
        edges.clear();
        int n, m, airport;
        cin >> n >> m >> airport;
        p.assign(n+1, 0);
        for(int i = 0 ; i <= n ; i++) p[i] = i;
        while(m--) {
            int a, b, w;
            cin >> a >> b >> w;
            if(w >= airport) continue;
            edges.push_back(Edge(a, b, w));
            edges.push_back(Edge(b, a, w));
        }
        sort(edges.begin(), edges.end(), cmp);
        int ans = 0;
        for(auto e:edges) {
            if(find_parent(e.from) != find_parent(e.to)) {
                p[find_parent(e.from)] = find_parent(e.to);
                ans += e.cost;
            }
        }
        set<int> s;
        for(int i = 1 ; i <= n ; i++) {
            s.insert(find_parent(i));
        }
        ans += s.size()*airport;
        cout << "Case #" << t++ << ": " << ans << " " << s.size() << endl;
    }
}
