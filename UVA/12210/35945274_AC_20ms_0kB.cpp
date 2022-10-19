#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> men, women;
    int B, S, t = 1;
    while(cin >> B >> S) {
        if(!B && !S) break;
        men.assign(B, 0);
        women.assign(S, 0);
        for(int i = 0 ; i < B ; i++) {
            cin >> men[i];
        }
        for(int i = 0 ; i < S ; i++) {
            cin >> women[i];
        }
        /*
        sort(men.begin(), men.end(), greater<int>());
        sort(women.begin(), women.end());
        int match = 0;
        for(int i = 0 ; i < men.size() ; i++) {
            if(women.empty()) break;
            auto it1 = lower_bound(women.begin(), women.end(), men[i]);
            auto it2 = upper_bound(women.begin(), women.end(), men[i]);
            it1 = (men[i]-*(it1) < *(it2)-men[i])? it1:it2;
            women.erase(it1);
            match++;
        }
        cout << "Case " << t++ << ": " << men.size()-match;
        if(men.size()-match) cout << " " << men.back();
        cout << endl;*/
        sort(men.begin(), men.end());
        cout << "Case " << t++ << ": ";
        if(B > S) {
            cout << B-S << " " << men[0];
        }
        else cout << 0;
        cout << endl;
    }
}
