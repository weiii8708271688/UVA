#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


int m, n;

void oil(bool**grid, int i, int j) {
    if(i < 0 || j < 0 || i >= m || j >= n) return;
    grid[i][j] = false;
    for(int k = -1 ; k < 2 ; k++) {
        for(int h = -1 ; h < 2 ; h++) {
            if(i+k < 0 || j+h < 0 || i+k >= m || j+h >= n) continue;
            if(grid[i+k][j+h]) {
                oil(grid, i+k, j+h);
            }
        }
    }
}


int main(){
    while(cin >> m >> n) {
        int ans = 0;
        if(!m && !n) break;
        char a;
        bool *grid[m];
        for(int i = 0 ; i < m ; i++) {
            grid[i] = new bool [n];
        }
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> a;
                if(a == '@') {
                    grid[i][j] = true;
                }else{
                    grid[i][j] = false;
                }
            }
        }
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j]) {
                    ans++;
                    oil(grid, i, j);
                }
            }
        }
        cout << ans << endl;
    }
}
