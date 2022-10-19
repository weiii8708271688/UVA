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

int parent[1001];


struct edge{
    int a, b, w;
};

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find_parent(int x) {
    if(parent[x] != x) return find_parent(parent[x]);
    else return x;
}


int main() {
    int m, n;
    while(cin >> n >> m) {
        if(!n && !m) break;
        vector <pair<int,int>> G[n];
        edge edges[m];
        int s = 0, min_w = INT_MAX;
        for(int i = 0 ; i < m ; i++) {
            cin >> edges[i].a >> edges[i].b >> edges[i].w;
        }
        sort(edges, edges+m, cmp);
        bool forest = true;
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        for(int i = 0 ; i < m ; i++) {
            //cout  << "now proceed :" << edges[i].a  << " " << edges[i].b << " " << edges[i].w <<endl;
            if(find_parent(edges[i].a) != find_parent(edges[i].b)) {
                parent[find_parent(edges[i].b)] = find_parent(edges[i].a);
            }else{
                if(forest) forest = false;
                else cout << " ";
                cout << edges[i].w;
            }
            for(int j = 0 ; j < n ; j++) {
                //cout << j << "'s parent is " << parent[j] << endl;
            }
            //cout << endl;
        }
        if(forest) cout << "forest";
        cout << endl;
    }
}
