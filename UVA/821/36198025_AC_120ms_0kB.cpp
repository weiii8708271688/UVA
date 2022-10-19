#include <bits/stdc++.h>
using namespace std;



int main() {
    int a, b, t = 1;
    while(cin >> a >> b) {
        if(!a && !b) break;
        vector<vector<int>> dist;
        set<int> s;
        dist.assign(101, vector<int>(101, 10000));
        do{
            s.insert(a);
            s.insert(b);
            dist[a][b] = 1;
            cin >> a >> b;
        }
        while(a && b);
        for(auto z:s) {
            for(auto i:s) {
                for(auto j:s) {
                    if(i == j) continue;
                    dist[i][j] = min(dist[i][j], dist[i][z]+dist[z][j]);
                }
            }
        }
        double sum = 0;
        for(auto i:s) {
            for(auto j:s) {
                if(i == j) continue;
                sum += dist[i][j];
            }
        }
        int Size = s.size();
        cout << "Case " << t++ << ": average length between pages = " << fixed << setprecision(3) << sum/(Size*(Size-1)) << " clicks" << endl;
    }
}

