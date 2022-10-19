    #include <vector>
    #include <iostream>
    #include <cmath>
    #include <cstring>
    #include <algorithm>
    #include <iomanip>
    using namespace std;

    struct node_{
        vector<int> s;
    };


    int main() {
        int n,l;
        while(cin >> n) {
            if(!n) break;
            cin >> l;
            node_ node[n];
            char color[n];
            char now;
            int startnum;
            bool ans = true;
            while(l--) {
                int temp1, temp2;
                cin >> temp1 >> temp2;
                node[temp1].s.push_back(temp2);
                node[temp2].s.push_back(temp1);
            }

            for(int i = 0 ; i < n ; i++) {
                color[i] = 'C';
                if(!node[i].s.empty()) {
                    startnum = i;
                }
            }
            color[startnum] = 'A';
            for(int i = 0 ; i < n ; i++) {
                if(!ans) break;
                for(int j =  0 ; j < n ; j++) {
                    if(color[j] != 'C') {
                        if(color[j] == 'A') now = 'B';
                        else now = 'A';
                        for(int k = 0 ; k < node[j].s.size() ; k++) {
                            int temp = node[j].s[k];
                            if(color[temp] == 'C') {
                                color[temp] = now;
                            }else if(color[temp] != now) ans = false;
                        }
                    }
                }
            }
            if(ans) {
                cout << "BICOLORABLE." << endl;
            }else {
                cout << "NOT BICOLORABLE." << endl;
            }
        }
    }
