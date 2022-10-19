#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
bool OK;
int autonum, n;
string s;
int patt[8][3] = { {0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1} };
int numbin[8] = {0};
void dfs(char ch, int now, int last1, int last2, int orin1, int orin2) {
    for(int i = 0 ; i < 8 ; i++) {
        if(numbin[i] == ch-'0') {
            if(patt[i][0] == last1 && patt[i][1] == last2) {
                if(now == n-1) {
                    if(patt[i][1] == orin1 && patt[i][2] == orin2) {OK = true; return;}
                }else{
                    dfs(s[now+1], now+1, patt[i][1], patt[i][2], orin1, orin2);
                }
            }
        }
    }
}

int main(){
    while(cin >> autonum >> n >> s) {
        OK = false;
        for(int i = 7 ; i >= 0 ; i--) {
            numbin[i] = autonum % 2;
            autonum/=2;
        }
        for(int i = 0 ; i < 8 ; i++) {
            if(numbin[i] == s[0]-'0') {
                dfs(s[1], 1, patt[i][1], patt[i][2], patt[i][0], patt[i][1]);
            }
        }
        if(OK) {
            cout << "REACHABLE" << endl;
        }else{
            cout << "GARDEN OF EDEN" << endl;
        }
    }
}
