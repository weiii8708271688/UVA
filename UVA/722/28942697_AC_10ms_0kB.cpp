#include <vector>
#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;

int ans, rowSize, colSize;
vector <string> grid;

void floodfill(int row, int col) {
    if(row >= rowSize || col >= colSize || row < 0 || col < 0) return;
    if(grid[row][col] == '0') {
        ans++;
        grid[row][col] = '1';
        floodfill(row+1, col);
        floodfill(row, col+1);
        floodfill(row, col-1);
        floodfill(row-1, col);
    }
    return;
}


int main(){
    string s;
    int n;
    cin >> n;
    while(n--) {
        grid.clear();
        rowSize = 1;
        colSize = 0;
        int row, col;
        char ch, ch2;
        cin >> ch >> ch2;
        row = (ch-'0') * 10 + (ch2-'0') - 1;
        cin >> ch >> ch2;
        col = (ch-'0') * 10 + (ch2-'0') - 1;
        getline(cin, s);
        getline(cin, s);
        colSize = s.size();
        grid.push_back(s);
        while(getline(cin, s)) {
            if(s != ""){
                grid.push_back(s);
                rowSize++;
            }else{
                break;
            }
        }
        ans = 0;
        floodfill(row, col);
        cout << ans << endl;
        if(n) cout << endl;
    }
}
