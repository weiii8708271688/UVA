#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

int grid[30][30][30];
int Z, Y, X;
queue <int> q;

int moveX[6] = {1,-1,0,0,0,0};
int moveY[6] = {0,0,1,-1,0,0};
int moveZ[6] = {0,0,0,0,1,-1};

bool isVaild(int x, int y, int z) {
    if(x >= X || x < 0) return false;
    if(y >= Y || y < 0) return false;
    if(z >= Z || z < 0) return false;
    return true;
}

void BFS() {
     while(!q.empty()) {
        int x, y, z;
        z = q.front(); q.pop();
        y = q.front(); q.pop();
        x = q.front(); q.pop();
        for(int i = 0 ;  i < 6 ; i++) {
            if(isVaild(x+moveX[i], y+moveY[i], z+moveZ[i]) && grid[z+moveZ[i]][y+moveY[i]][x+moveX[i]] == 0) {
                grid[z+moveZ[i]][y+moveY[i]][x+moveX[i]] = grid[z][y][x]+1;
                q.push(z+moveZ[i]);
                q.push(y+moveY[i]);
                q.push(x+moveX[i]);
            }
        }
     }
}


int main() {
    while(cin >> Z >> Y >> X) {
        if(!Z && !Y && !X) break;
        int e[3];
        for(int i = 0 ; i < Z ; i++) {
            for(int j = 0 ; j < Y ; j++) {
                for(int k = 0 ; k < X ; k++) {
                    char ch;
                    cin >> ch;
                    if(ch == '#') {
                        grid[i][j][k] = -1;
                    }else{
                        grid[i][j][k] = 0;
                    }
                    if(ch == 'S') {
                        q.push(i);
                        q.push(j);
                        q.push(k);
                        grid[i][j][k] = 1;
                    }
                    if(ch == 'E') {
                        e[0] = i;
                        e[1] = j;
                        e[2] = k;
                    }
                }
            }
        }
        BFS();
        if(grid[e[0]][e[1]][e[2]]) {
            cout << "Escaped in " << grid[e[0]][e[1]][e[2]]-1  << " minute(s)." << endl;
        }else{
            cout << "Trapped!" << endl;
        }
    }
}
