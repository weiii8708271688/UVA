#include <bits/stdc++.h>
using namespace std;

vector <vector<pair<int, int>>> Gy, Gt;
vector <int> Dy, Dt;

void read(vector <vector<pair<int, int>>> &G) {
    char ch, a, b;
    int w;
    cin >> ch >> a >> b >> w;
    G[a-'A'].push_back(make_pair(b-'A', w));
    if(ch == 'B') {
        G[b-'A'].push_back(make_pair(a-'A', w));
    }

}


void bfs(vector <vector<pair<int, int>>> G, vector<int> &D, char s) {
    queue <int> q;
    q.push(s-'A');
    D[s-'A'] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v: G[u]) {
            if(D[v.first] == INT_MAX || D[v.first] > D[u] + v.second) {
                D[v.first] = D[u] + v.second;
                q.push(v.first);
            }
        }
    }
}


int main() {
    int n;
    char ch;
    while(cin >> n) {
        if(!n) break;
        Gy.assign(26, vector<pair<int, int>>());
        Gt.assign(26, vector<pair<int, int>>());
        Dy.assign(26, INT_MAX);
        Dt.assign(26, INT_MAX);
        for(int i = 0 ; i < n ; i++) {
            cin >> ch;
            if(ch == 'Y') {
                read(Gy);
            }else{
                read(Gt);
            }
        }
        cin >> ch;
        bfs(Gy, Dy, ch);
        cin >> ch;
        bfs(Gt, Dt, ch);
        int sum = INT_MAX;
        vector <char> output;
        for(int i = 0 ; i < 26 ; i++) {
            if(Dt[i] + Dy[i] >= 0 && Dt[i] + Dy[i] < sum) {
                sum = Dt[i] + Dy[i];
            }
        }
        for(int i = 0 ; i < 26 ; i++) {
            if(Dt[i] + Dy[i] == sum) {
                output.push_back(i + 'A');
            }
        }
        if(sum == INT_MAX) {
            cout << "You will never meet." << endl;
        }else{
            cout << sum;
            for(int i = 0 ; i < output.size() ; i++) {
                cout << " " << output[i];
            }
            cout << endl;
        }
    }
}

