#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
#include <map>
using namespace std;

struct coor{
    int x,y;
};

coor S, T;
int grid[25][25];
int m, n;
bool canReach() {
    queue <int> q;
    q.push(S.x);
    q.push(S.y);
    while(!q.empty()) {
        /*for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cout << setw(2) << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
        */
        int x = q.front();q.pop();
        int y = q.front();q.pop();
        grid[x][y] = 1;
        for(int i = -1 ; i <= 1 ; i++) {
            for(int j = -1 ; j <= 1 ; j++) {
                if(i && j) continue;
                int tx = x+i;
                int ty = y+j;
                if(tx >= 0 && tx < m && ty >= 0 && ty < n) {
                    if(grid[tx][ty] == 0) {
                        grid[tx][ty] = grid[x][y]+1;
                        q.push(tx);
                        q.push(ty);
                    }
                }
            }
        }
    }
    if(grid[T.x][T.y] != 0) {
        return true;
    }
    return false;
}
//N = 0 S = 1 W 2 E 3
int bfs() {
    queue <int> q; // x y dir color
    int been[m][n][4][5];
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            for(int k = 0 ; k < 4 ; k++) {
                for(int z = 0 ; z < 5 ; z++) {
                    been[i][j][k][z] = -1;
                }
            }
        }
    }
    been[S.x][S.y][0][0] = 0;
    q.push(S.x);
    q.push(S.y);
    q.push(0);
    q.push(0);
    while(true) {
        //cout << endl;
        for(int i = 0 ; i < 4 ; i++) {
            if(been[T.x][T.y][i][0] != -1) {
                return been[T.x][T.y][i][0];
            }
        }
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int dir = q.front(); q.pop();
        int color = q.front(); q.pop();
        //cout << "now been[" << x << "]" << "[" << y << "]" << "[" << dir << "]" << "[" << color << "] sec == " << been[x][y][dir][color] << endl;
        int turn[2];
        switch(dir) {
            case 0: turn[0] = 2; turn[1] = 3; break;
            case 1: turn[0] = 2; turn[1] = 3; break;
            case 2: turn[0] = 0; turn[1] = 1; break;
            case 3: turn[0] = 0; turn[1] = 1; break;
        }
        for(int i = 0 ; i < 2 ; i++) {
            if(been[x][y][turn[i]][color] == -1) {
                //cout << "been[" << x << "]" << "[" << y << "]" << "[" << turn[i] << "]" << "[" << color << "] has add~~" << endl;
                been[x][y][turn[i]][color] = been[x][y][dir][color]+1;
                q.push(x);
                q.push(y);
                q.push(turn[i]);
                q.push(color);
            }
        }
        switch(dir) {
            case 0: turn[0] = x-1; turn[1] = y; break;
            case 1: turn[0] = x+1; turn[1] = y; break;
            case 2: turn[0] = x; turn[1] = y-1; break;
            case 3: turn[0] = x; turn[1] = y+1; break;
        }
        if(turn[0] >= 0 && turn[0] < m && turn[1] >= 0 && turn[1] < n) {
            if(been[turn[0]][turn[1]][dir][(color+1)%5] == -1 && grid[turn[0]][turn[1]] != -1) {
                //cout << "been[" << turn[0] << "]" << "[" << turn[1] << "]" << "[" << dir << "]" << "[" << (color+1)%5 << "] has add~~" << endl;
                been[turn[0]][turn[1]][dir][(color+1)%5] = been[x][y][dir][color]+1;
                q.push(turn[0]);
                q.push(turn[1]);
                q.push(dir);
                q.push((color+1)%5);
            }
        }
    }
}


int main() {
    int c = 0;
    while(cin >> m >> n) {
        if(!m, !n) break;
        if(c) cout << endl;
        cout << "Case #" << ++c << endl;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                char ch;
                cin >> ch;
                if(ch == '#') {
                    grid[i][j] = -1;
                }else{
                    grid[i][j] = 0;
                }
                if(ch == 'S') {
                    S.x = i;
                    S.y = j;
                }
                if(ch == 'T') {
                    T.x = i;
                    T.y = j;
                }
            }
        }
        if(!canReach()) {
            cout << "destination not reachable" << endl;
        }else{
            cout << "minimum time = " << bfs() << " sec" <<endl;
        }
    }
}
