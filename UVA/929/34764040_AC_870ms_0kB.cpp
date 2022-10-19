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
using namespace std;
int row, col;
int grid[1001][1001];
int ans[1001][1001];
int drow[4] = {0,0,1,-1};
int dcol[4] = {1,-1,0,0};


struct coor{
    int x, y, w;
    bool operator> (const coor& a) const{
        return a.w < w;
    }
};


void bfs() {
    priority_queue <coor, vector<coor>, greater<coor>> pq;
    coor tmp;
    tmp.x = tmp.y = 0;
    tmp.w = grid[0][0];
    pq.push(tmp);
    ans[0][0] = grid[0][0];
    while(!pq.empty()) {
        tmp = pq.top();pq.pop();
        int nrow = tmp.x;
        int ncol = tmp.y;
        for(int i = 0 ; i < 4 ; i++) {
            int trow = nrow + drow[i];
            int tcol = ncol + dcol[i];
            if(trow >= 0 && tcol >= 0 && trow < row && tcol < col) {
                if(ans[trow][tcol] == -1 || ans[trow][tcol] > ans[nrow][ncol] + grid[trow][tcol]) {
                    ans[trow][tcol] = ans[nrow][ncol] + grid[trow][tcol];
                    coor tmp2;
                    tmp2.x = trow;
                    tmp2.y = tcol;
                    tmp2.w = ans[trow][tcol];
                    pq.push(tmp2);
                }
            }
        }
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> row >> col;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                cin >> grid[i][j];
                ans[i][j] = -1;
            }
        }
        bfs();
        cout << ans[row-1][col-1] << endl;
    }


}
