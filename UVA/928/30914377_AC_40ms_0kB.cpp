#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;


int Map[4][301][301]; // 0 = cinmark, 1 = 1hadbeen, 2 = 2hadbeen, 3 = 3hadbeen
queue <int> q;
int stoprow, stopcol, Row, Col;

int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};

void bfs() {
    int row, col, num;
    while(!q.empty()) {
        row = q.front(); q.pop();
        col = q.front(); q.pop();
        num = q.front(); q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            bool CanGo = true;
            int trow = row, tcol = col;
            int temp;
            if(num == 1) temp = 2;
            if(num == 2) temp = 3;
            if(num == 3) temp = 1;
            for(int j = 0 ; j < num ; j++) {
                trow += drow[i];
                tcol += dcol[i];
                if(trow >= Row || trow < 0 || tcol >= Col || tcol < 0) {
                    CanGo = false;
                }
                if(!Map[0][trow][tcol]) {
                    CanGo = false;
                }
            }
            if(CanGo) {
                if(!Map[temp][trow][tcol]) {
                    q.push(trow);
                    q.push(tcol);
                    q.push(temp);
                    Map[temp][trow][tcol] = Map[num][row][col]+1;
                }
            }
        }
    }
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        cin >> Row >> Col;
        for(int i = 0 ; i < Row ; i++) {
            for(int j = 0 ; j < Col ; j++) {
                Map[1][i][j] = 0;
                Map[2][i][j] = 0;
                Map[3][i][j] = 0;
                char ch;
                cin >> ch;
                if(ch == '#') {
                    Map[0][i][j] = 0;
                }else{
                    Map[0][i][j] = 1;
                }
                if(ch == 'S') {
                    Map[1][i][j] = 1;
                    q.push(i);
                    q.push(j);
                    q.push(1);
                }
                if(ch == 'E') {
                    stoprow = i;
                    stopcol = j;
                }
            }
        }
        bfs();
        int ans = 0;
        for(int i = 1 ; i < 4 ; i++) {
            if(Map[i][stoprow][stopcol]) {
                if(ans == 0 || Map[i][stoprow][stopcol] < ans) {
                    ans = Map[i][stoprow][stopcol];
                }
            }
        }
        if(ans) {
            cout << ans-1 << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
