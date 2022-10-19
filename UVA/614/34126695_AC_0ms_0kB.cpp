#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

int drow[4] = {0,-1,0,1};
int dcol[4] = {-1,0,1,0};
int maze[13][13];
int ans[13][13];


void DFS(int row, int col, int currow, int curcol, int erow, int ecol, int num) {
    ans[currow][curcol] = num;
    if(currow == erow && curcol == ecol) return;
    for(int i = 0 ; i < 4; i++) {
        int trow = currow + drow[i], tcol = curcol + dcol[i];
        bool pass = true;
        if(!trow || !tcol || trow > row || tcol > col) continue;
        if(i == 0) {
            if(maze[trow][tcol] == 1 || maze[trow][tcol] == 3) pass = false;
        }else if(i == 1) {
            if(maze[trow][tcol] == 2 || maze[trow][tcol] == 3) pass = false;
        }else if(i == 2) {
            if(maze[currow][curcol] == 1 || maze[currow][curcol] == 3) pass = false;
        }else{
            if(maze[currow][curcol] == 2 || maze[currow][curcol] == 3) pass = false;
        }
        if(pass && !ans[trow][tcol]) {
            DFS(row, col, trow, tcol, erow, ecol, num+1);
            if(ans[erow][ecol]) return;
        }
    }
    if(!ans[erow][ecol]) ans[currow][curcol] = 1000;
}



int main() {
    int row, col, t = 1;
    while(cin >> row >> col) {
        if(!row && !col) break;
        int srow, scol, erow, ecol;
        cin >> srow >> scol >> erow >> ecol;
        for(int i = 1 ; i <= row ; i++) {
            for(int j = 1 ; j <= col ; j++) {
                cin >> maze[i][j];
                ans[i][j] = 0;
            }
        }
        DFS(row, col, srow, scol, erow, ecol, 1);
        cout << "Maze " << t++ << endl << endl;
        cout << "+";
        for(int i = 0 ; i < col ; i++) {
            cout << "---+";
        }
        cout << endl;
        for(int i = 1 ; i <= row ; i++) {
            cout << "|";
            for(int j = 1; j <= col ; j++) {
                if(ans[i][j] == 1000) cout << "???";
                else if(!ans[i][j]) cout << "   ";
                else cout << setw(3) << ans[i][j];
                if(maze[i][j] == 1 || maze[i][j] == 3 || j == col) cout << "|";
                else cout << " ";
            }
            cout << endl;
            cout << "+";
            for(int j = 1 ; j <= col ; j++) {
                if(maze[i][j] == 2 || maze[i][j] == 3 || i == row) cout << "---+";
                else cout << "   +";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
}
