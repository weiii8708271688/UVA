#include <bits/stdc++.h>
using namespace std;

stack <int> s;
vector<pair<int, int>> beads;
vector<bool> visit;
int n;


void DFS(int u) {
    visit[u] = true;
    for(int i = 0 ; i < n ; i++) {
        if(beads[u].second == beads[i].first && !visit[i]) {
            s.push(i);
            DFS(i);
        }
        if(beads[u].second == beads[i].second && !visit[i]) {
            s.push(i);
            swap(beads[i].first, beads[i].second);
            DFS(i);
        }
    }
    cout << beads[u].second << " " << beads[u].first << endl;

}


int main() {
    int T, t = 1;
    cin >> T;
    while(T--) {
        cin >> n;
        int eular[51] = {};
        beads.clear();
        visit.assign(n, false);
        for(int i = 0 ; i < n ; i++) {
            int a, b;
            cin >> a >> b;
            beads.push_back(make_pair(a,b));
            eular[a]++;
            eular[b]++;
        }
        int odd = 0, odd_pos = 0;
        for(int i = 1 ; i < 51 ; i++) {
            if(eular[i]%2) {
                if(!odd) odd_pos = i;
                odd++;
            }
        }


        cout << "Case #" << t++ << endl;

        if(!odd) {
            while(!s.empty()) {
                s.pop();
            }
            s.push(odd_pos);
            DFS(odd_pos);
        }else{
            cout << "some beads may be lost" << endl;
        }
        if(T) cout << endl;

    }
}
