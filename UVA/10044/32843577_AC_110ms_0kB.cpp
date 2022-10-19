#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
#include <map>
using namespace std;


vector <string> name;
vector <vector <int>> relate;
queue <int> q;

string unspace(string s) {
    while(s[0] == ' ') {
        s.erase(s.begin());
    }
    while(s[s.size()-1] == ' ') {
        s.erase(s.end()-1);
    }
    return s;
}

void trans(string s) {
    vector <int> temp_list;
    string temp;
    int count = 0;
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] == ':') {
            temp = unspace(temp);
            bool n = true;
            for(int j = 0 ; j < name.size() ; j++) {
                if(name[j] == temp) {
                    temp_list.push_back(j);
                    n = false;
                    break;
                }
            }
            if(n) {
                vector <int> t;
                relate.push_back(t);
                temp_list.push_back(name.size());
                name.push_back(temp);
            }
            temp = "";
            break;
        }
        if(s[i] == ',') {
            count++;
        }
        if(count == 2) {
            temp = unspace(temp);
            bool n = true;
            for(int j = 0 ; j < name.size() ; j++) {
                if(name[j] == temp) {
                    temp_list.push_back(j);
                    n = false;
                    break;
                }
            }
            if(n) {
                vector <int> t;
                relate.push_back(t);
                temp_list.push_back(name.size());
                name.push_back(temp);
            }
            temp = "";
            count = 0;
            continue;
        }
        temp += s[i];
    }
    for(int i = 0 ; i < temp_list.size() ; i++) {
        int l = temp_list[i];
        for(int j = 0 ; j < temp_list.size() ; j++) {
            if(i == j) continue;
            int r = temp_list[j];
            relate[l].push_back(r);
        }
    }
}



int main() {
    int sero;
    cin >> sero;
    for(int x = 1 ; x <= sero ; x++) {
        string s;
        name.clear();
        relate.clear();
        cout << "Scenario " << x << endl;
        int m, n;
        cin >> m >> n;
        cin.ignore();
        while(m--) {
            getline(cin, s);
            trans(s);
        }
        int ans[name.size()];
        int erdo = -1;
        for(int i = 0 ; i < name.size() ; i++) {
            ans[i] = -1;
            if(name[i] == "Erdos, P.") {
                ans[i] = 0;
                erdo = i;
            }
        }
        q.push(erdo);
        while(!q.empty()) {
            int a = q.front();q.pop();
            for(int i = 0 ; i < relate[a].size() ; i++) {
                int r = relate[a][i];
                if(ans[r] == -1) {
                    ans[r] = ans[a]+1;
                    q.push(r);
                }
            }
        }
        while(n--) {
            getline(cin, s);
            cout << s << " ";
            s = unspace(s);
            bool op = false;
            for(int i = 0 ; i < name.size() ; i++) {
                if(name[i] == s) {
                    if(ans[i] == -1) {
                        cout << "infinity" << endl;
                    }else{
                        cout << ans[i] << endl;
                    }
                    op = true;
                }
            }
            if(!op) cout << "infinity" << endl;
        }
    }
}
