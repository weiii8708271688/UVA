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
#include <sstream>

using namespace std;
vector <vector<int>> adjlist, G;
int f, s, t, poscount;

map <string, int> name, party, club;

void maxflow() {
    while(true) {
        queue <int> q;
        q.push(s);
        int flow[t+1] = {0};
        flow[s] = INT_MAX;
        int p[t+1];
        for(int i = 0 ; i <= t ; i++) p[i] = -1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto v: adjlist[u]) {
                if(!flow[v] && G[u][v] > 0) {
                    p[v] = u;
                    flow[v] = min(flow[u], G[u][v]);
                    q.push(v);
                }
            }
        }
        if(!flow[t]) break;
        for(int v = t ; v != 0 ;) {
            int u = p[v];
            G[u][v] -= flow[t];
            G[v][u] += flow[t];
            v = u;
        }
        f += flow[t];
    }
}




void dealstring(string s) {
    string temp = "";
    int namepos, partypos;
    vector <int> clubpos;
    stringstream sin(s);
    sin >> temp;
    if(name.find(temp) == name.end()) {
        name[temp] = poscount++;
    }
    namepos = name[temp];
    sin >> temp;
    if(party.find(temp) == party.end()) {
        party[temp] = poscount++;
    }
    partypos = party[temp];
    while(sin >> temp) {
        if(club.find(temp) == club.end()) {
                club[temp] = poscount++;
            }
        clubpos.push_back(club[temp]);
    }

    /*string::iterator it = s.begin();
    for(;it != s.end(); it++) {
        if(*it == ' ') {
            name[temp] = poscount++;
            namepos = name[temp];
            temp = "";
            break;
        }
        temp += (*it);
    }
    it++;
    for(;it != s.end(); it++) {
        if(*it == ' ') {
            if(party.find(temp) == party.end()) {
                party[temp] = poscount++;
            }
            partypos = party[temp];
            temp = "";
            break;
        }
        temp += (*it);
    }
    it++;
    for(;it != s.end(); it++) {
        if(*it != ' ') temp += (*it);
        if((*it) == ' ' || it == s.end()-1) {
            if(club.find(temp) == club.end()) {
                club[temp] = poscount++;
            }
            clubpos.push_back(club[temp]);
            temp = "";
            continue;
        }
    }*/

    for(auto v:clubpos) {
        G[0][v] = 1;
        adjlist[0].push_back(v);
        adjlist[v].push_back(0);
        G[v][namepos] = 1;
        adjlist[v].push_back(namepos);
        adjlist[namepos].push_back(v);
    }
    G[namepos][partypos] = 1;
    adjlist[namepos].push_back(partypos);
    adjlist[partypos].push_back(namepos);
    return;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    string str;
    cin >> n;
    getline(cin, str);
    getline(cin, str);
    while(n--) {
        G.clear();
        adjlist.clear();
        name.clear();
        party.clear();
        club.clear();
        G.assign(3000, vector<int>(3000));
        adjlist.assign(3000, vector<int>());
        s = 0;
        f = 0;
        poscount = 1;
        while(getline(cin, str)) {
            if(str == "") break;
            dealstring(str);
        }
        t = poscount;
        int maximum = (club.size()+1)/2-1;
        for(auto u:party) {
            G[u.second][t] = maximum;
            adjlist[u.second].push_back(t);
            adjlist[t].push_back(u.second);
        }
        //cout << "club.size() : " << club.size() << endl;
        //cout << "f == " << f << endl;
        maxflow();
        if(club.size() == f) {
            for(auto u:club) {
                for(auto v:name) {
                    //cout << "G[" << u.first << "][" << v.first << "] == " << G[u.second][v.second] << endl;
                    if(G[v.second][u.second] == 1) {
                        cout << v.first << " " << u.first << endl;
                        break;
                    }
                }
            }
        }else{
            cout << "Impossible." << endl;
        }
        if(n) cout << endl;
    }
}
