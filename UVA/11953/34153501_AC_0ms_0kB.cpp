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

int ship[101][101];
int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};


void floodfill(int row, int col, int currow, int curcol) {
    ship[currow][curcol] = 0;
    int ans = 1;
    for(int i = 0 ; i < 4 ; i++) {
        int trow = currow + drow[i];
        int tcol = curcol + dcol[i];
        if(trow > row || trow < 0 || tcol > col || tcol < 0) continue;
        if(ship[trow][tcol]) floodfill(row, col, trow, tcol);
    }
}


int main() {
    int c;
    cin >> c;
    for(int t = 1 ; t <= c; t++) {
        int row;
        cin >> row;
        getchar();
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < row ;j++) {
                char ch = getchar();
                if(ch == '.') {
                    ship[i][j] = 0;
                }else if(ch == 'x') {
                    ship[i][j] = 1;
                }else{
                    ship[i][j] = 2;
                }
            }
            getchar();
        }
        int ans = 0;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < row ; j++) {
                if(ship[i][j] == 1) {
                    floodfill(row, row, i, j);
                    ans++;
                }
            }
        }
        cout << "Case " << t << ": " << ans << endl;
    }
}
