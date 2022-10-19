#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, a;
    while(cin >> n >> m) {
        if(!n && !m) break;
        vector<int> head;
        vector<int> knight;
        for(int i = 0 ; i < n ; i++) {
            cin >> a;
            head.push_back(a);
        }
        for(int i = 0 ; i < m ; i++) {
            cin >> a;
            knight.push_back(a);
        }
        bool success = true;
        sort(head.begin(), head.end());
        sort(knight.begin(), knight.end());
        int ans = 0;
        for(int i = 0 ; i < head.size() ; i++) {
            auto it = lower_bound(knight.begin(), knight.end(), head[i]);
            if(it != knight.end()){
                ans += *(it);
                knight.erase(it);
            }else{
                success = false;
                break;
            }
        }
        if(success) {
            cout << ans << endl;
        }else{
            cout << "Loowater is doomed!" << endl;
        }

    }
}
