#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <ctime>
#include <queue>
using namespace std;

int drow[4] = {0,0,1,-1};
int dcol[4] = {1,-1,0,0};

int main() {
    int row, col;
    while(cin >> row >> col) {
        if(!row && !col) break;
        int grid[row][col], ans[row][col];
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                grid[i][j] = 1;
                ans[i][j] = 0;
            }
        }
        int n;
        cin >> n;
        while(n--) {
            int a, b, m;
            cin >> a >> m;
            while(m--) {
                cin >> b;
                grid[a][b] = 0;
            }
        }
        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;
        queue <int> q;
        ans[s_x][s_y] = 1;
        q.push(s_x);
        q.push(s_y);
        while(!q.empty()) {
            int nowrow = q.front(); q.pop();
            int nowcol = q.front(); q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int trow = nowrow + drow[i];
                int tcol = nowcol + dcol[i];
                if(trow >= 0 && tcol >= 0 && trow < row && tcol < col) {
                    if(!ans[trow][tcol] && grid[trow][tcol]) {
                        ans[trow][tcol] = ans[nowrow][nowcol] + 1;
                        q.push(trow);
                        q.push(tcol);
                    }
                }
            }
        }

//        for(int i= 0; i < row ; i++) {
//            for(int j = 0 ; j < col ; j++) {
//                cout << ans[i][j] << " ";
//            }
//            cout << endl;
//        }


        cout << ans[e_x][e_y]-1 << endl;
    }
}
