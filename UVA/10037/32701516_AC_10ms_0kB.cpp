#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        int sec[m];
        for(int i = 0 ; i < m ; i++) {
            cin >> sec[i];
        }
        if(m == 1) {
            cout << sec[0] << endl << sec[0] << endl;
            if(n) cout << endl;
            continue;
        }
        sort(sec, sec+m);
        int ans = 0, pointer = m-1;
        vector <int> output;
        while(m > 3) {
            int planA = sec[0] + 2*sec[1] + sec[pointer];
            int planB = 2*sec[0] + sec[pointer-1] + sec[pointer];
            if(planA <= planB) {
                output.push_back(0);output.push_back(1);
                output.push_back(0);
                output.push_back(pointer-1);output.push_back(pointer);
                output.push_back(1);
                ans+=planA;
            }else{
                output.push_back(0);output.push_back(pointer-1);
                output.push_back(0);
                output.push_back(0);output.push_back(pointer);
                output.push_back(0);
                ans+=planB;
            }
            pointer-=2;
            m-=2;
        }
        output.push_back(0);output.push_back(1);
        ans+=sec[1];
        if(m == 3) {
            output.push_back(0);
            output.push_back(0);output.push_back(2);
            ans+=(sec[0]+sec[2]);
            pointer--;
            m--;
        }
        cout << ans << endl;
        bool s = true;
        for(int i = 0 ; i < output.size() ; i++) {
            if(s) {
                s = false;
                cout << sec[output[i]] << " " <<sec[output[i+1]] << endl;
                i++;
            }else{
                s = true;
                cout << sec[output[i]] << endl;
            }
        }
        if(n) cout << endl;
    }
}
