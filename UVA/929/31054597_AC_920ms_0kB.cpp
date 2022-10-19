#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <limits.h>
#include <ctime>
using namespace std;

int row, col;
int grid[1001][1001];
int ans[1001][1001];
bool visited[1001][1001];
struct coor{

    bool operator <(const coor& c) const {
        return(c.val < val);
    }

    int x;
    int y;
    int val;
};
priority_queue <coor> q;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dij() {
    while(!q.empty()) {
        coor temp = q.top(); q.pop();
        int tx, ty, tans;
        visited[temp.x][temp.y] = true;
        for(int i = 0 ; i < 4 ; i++) {
            tx = temp.x + dx[i];
            ty = temp.y + dy[i];
            if(tx && ty && tx <= row && ty <= col && !visited[tx][ty]) {
                tans = temp.val + grid[tx][ty];
                if(tans < ans[tx][ty]) {
                    coor temp2;
                    temp2.x = tx;
                    temp2.y = ty;
                    temp2.val = tans;
                    ans[tx][ty] = tans;
                    q.push(temp2);
                }
            }
        }
    }
}


int main() {
    int c;
    cin >> c;
    while(c--) {
        cin >> row >> col;
        for(int i = 1 ; i <= row ; i++) {
            for(int j = 1 ; j <= col ; j++) {
                cin >> grid[i][j];
                ans[i][j] = INT_MAX;
                visited[i][j] = false;
            }
        }
        coor temp;
        temp.x = 1; temp.y = 1; temp.val = grid[1][1];
        ans[1][1] = grid[1][1];
        q.push(temp);
        dij();
        cout << ans[row][col] << endl;
    }
}
