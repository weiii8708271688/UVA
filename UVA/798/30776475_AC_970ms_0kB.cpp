#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

int w[11];
int h[11];
int num[11];
int W,H,n,ans;
bool grid[100][100];


bool drawtry(int x, int y, int tempw, int temph) {
    if (x + tempw > W || y + temph > H) return false;
    for(int i = 0 ; i < tempw ; i++) {
        for(int j = 0 ; j < temph ; j++) {
            if(grid[x+i][y+j]) return false;
        }
    }
    return true;
}

void draw(int x, int y, int tempw, int temph, bool TorF) {
    for(int i = 0 ; i < tempw ; i++) {
        for(int j = 0 ; j < temph ; j++) {
            grid[x+i][y+j] = TorF;
        }
    }
}

void dfs(int x, int y) {
    if(x >= W) {
        y++;
        x = 0;
    }
    if(y >= H) {
        ans++;return;
    }
    if(!grid[x][y]) {
        for(int i = 0 ; i < n ; i++) {
            if(num[i]) {
                if(drawtry(x, y, w[i], h[i])) {
                    draw(x, y, w[i], h[i], true); num[i]--;
                    dfs(x+1, y);
                    draw(x, y, w[i], h[i], false); num[i]++;
                }
                if(drawtry(x, y, h[i], w[i]) && w[i]!=h[i]) {
                    draw(x, y, h[i], w[i], true); num[i]--;
                    dfs(x+1, y);
                    draw(x, y, h[i], w[i], false); num[i]++;
                }
            }
        }
    }else{
        dfs(x+1, y);
    }
}
int main() {
    while(cin >> W >> H >> n) {
        ans = 0;
        for(int i = 0 ; i < W ; i++) {
            for(int j = 0 ; j < H ; j++) {
                grid[i][j] = 0;
            }
        }
        for(int i = 0 ; i < n ; i++) {
            cin >> num[i] >> w[i] >> h[i];
        }
        dfs(0,0);
        cout << ans << endl;
    }
}
