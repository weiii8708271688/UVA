#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> fri[n];
    for(int a = 0 ; a < n ; a++) {
        int m;
        cin >> m;
        while(m--) {
            int b;
            cin >> b;
            fri[a].push_back(b);
        }
    }
    int casenum;
    cin >> casenum;
    while(casenum--) {
        int first;
        cin >> first;
        bool whoknow[n] = {0};
        int M = 1, D = 1, day = 0;
        vector <int> q;
        q.push_back(first);
        whoknow[first] = true;
        if(fri[first].empty()) {
            cout << 0 << endl;
            continue;
        }
        while(!q.empty()) {
            day++;
            int temp = 0;
            vector <int> tempque;
            for(int i = 0 ; i < q.size() ; i++) {
                for(int j = 0 ; j < fri[q[i]].size() ; j++) {
                    if(!whoknow[fri[q[i]][j]]) {
                        whoknow[fri[q[i]][j]] = true;
                        tempque.push_back(fri[q[i]][j]);
                        temp++;
                    }
                }
            }
            if(temp > M) {
                M = temp;
                D = day;
            }
            q = tempque;
        }
        cout << M << " " << D << endl;
    }

}
