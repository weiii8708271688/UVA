#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
using namespace std;

char Map[21][21];
bool land[21][21];
int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};


int floodfill(int row, int col, int currow, int curcol) {
    land[currow][curcol] = false;
    int ans = 1;
    for(int i = 0 ; i < 4 ; i++) {
        int trow = currow + drow[i];
        int tcol = col + curcol + dcol[i];
        if(trow > row || trow < 0) continue;
        tcol %= col;
        if(land[trow][tcol]) ans += floodfill(row, col, trow, tcol);
    }
    return ans;
}


int main() {
    int row, col;
    while(cin >> row >> col) {
        getchar();
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                Map[i][j] = getchar();
            }
            getchar();
        }
        int krow, kcol;
        cin >> krow >> kcol;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0;  j < col ; j++) {
                land[i][j] = (Map[i][j] == Map[krow][kcol]? 1 : 0);
            }
        }
        int ans = 0;
        floodfill(row, col, krow, kcol);

        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(land[i][j]) {
                    ans = max(ans, floodfill(row, col, i, j));
                }
            }
        }
        cout << ans << endl;
    }
}
