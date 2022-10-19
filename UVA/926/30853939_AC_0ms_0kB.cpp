#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

struct pos{
    int x;
    int y;
    char way;
};

long long path[31][31];
bool node[31][31][5]; //N = 0, E = 1, W = 2, S = 3 hadbeen = 4;
pos start, stop, temp;
long long n, ans;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
void init() {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            path[i][j] = 0;
            for(int k = 0 ; k < 4 ; k++) {
                node[i][j][k] = true;
                if(i == 1) {
                    node[i][j][2] = false;
                }
                if(j == 1) {
                    node[i][j][3] = false;
                }
                if(i == n+1) {
                    node[i][j][1] = false;
                }
                if(j == n+1) {
                    node[i][j][0] = false;
                }
            }
            node[i][j][4] = false;
        }
    }
}



int main() {
    int c;
    cin >> c;
    while(c--) {
        int w;
        cin >> n;
        init();
        cin >> start.x >> start.y >> stop.x >> stop.y;
        cin >> w;
        for(int i = 0 ; i < w ; i++) {
            cin >> temp.x >> temp.y >> temp.way;
            if(temp.way == 'N') {
                node[temp.x][temp.y][0] = false;
                node[temp.x][temp.y+1][3] = false;
            }else if(temp.way == 'E') {
                node[temp.x][temp.y][1] = false;
                node[temp.x+1][temp.y][2] = false;
            }else if(temp.way == 'W') {
                node[temp.x][temp.y][2] = false;
                node[temp.x-1][temp.y][1] = false;
            }else if(temp.way == 'S') {
                node[temp.x][temp.y][3] = false;
                node[temp.x][temp.y-1][0] = false;
            }
        }
        path[start.x][start.y] = 1;
        for(int i = start.x ; i < n+1 ; i++) {
            for(int j = start.y ; j < n+1 ; j++) {
                if(node[i][j][2] && node[i][j][3]) {
                    path[i][j] = max(path[i][j-1] + path[i-1][j], path[i][j]);
                }else if(node[i][j][2]) {
                    path[i][j] = max(path[i+dx[2]][j+dy[2]], path[i][j]);
                }else if(node[i][j][3]) {
                    path[i][j] = max(path[i+dx[3]][j+dy[3]], path[i][j]);
                }
            }
        }
        cout << path[stop.x][stop.y] << endl;
    }
}
