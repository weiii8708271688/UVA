#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;
int Xmove[8] = {1,1,-1,-1,2,2,-2,-2};
int Ymove[8] = {2,-2,2,-2,1,-1,1,-1};
int grid[8][8];
queue <int> q;
void bfs() {
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        for(int i = 0 ; i < 8 ; i++) {
            int tempx = x+Xmove[i];
            int tempy = y+Ymove[i];
            if(!grid[tempx][tempy] && tempx < 8 && tempx >= 0 && tempy < 8 && tempy >= 0) {
                q.push(tempx);
                q.push(tempy);
                grid[tempx][tempy] = grid[x][y]+1;
            }
        }
    }
}

int main() {
    string s;
    while(cin >> s) {
        cout << "To get from " << s;
        for(int i = 0 ; i < 8 ; i++) {
            for(int j = 0 ; j < 8 ; j++) {
                grid[i][j] = 0;
            }
        }
        int x = s[0] - 'a',y = s[1] - '1';
        grid[x][y] = 1;
        q.push(x);
        q.push(y);
        bfs();
        cin >> s;
        x = s[0] - 'a',y = s[1] - '1';
        cout << " to " << s << " takes " << grid[x][y]-1 << " knight moves." << endl;
    }
}
