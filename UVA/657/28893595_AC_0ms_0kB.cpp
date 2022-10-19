#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int col, row, countans;

void floodfill(int** grid, int i, int j) {
    if(i >= col || i < 0 || j >= row || j < 0) return;
    if(grid[i][j] == 1){
        grid[i][j] = 2;
        floodfill(grid, i+1, j);
        floodfill(grid, i, j+1);
        floodfill(grid, i-1, j);
        floodfill(grid, i, j-1);
    }
}

void check (int** grid,int i,int j) {
    if(i >= col || i < 0 || j >= row || j < 0) return;
    if(grid[i][j] == 0) return;
    if(grid[i][j] == 1) {
        floodfill(grid, i, j);
        countans++;
    }
    if(grid[i][j] == 2) {
        grid[i][j] = 0;
        check(grid, i, j-1);
        check(grid, i, j+1);
        check(grid, i-1, j);
        check(grid, i+1, j);
    }
}

int main(){
    int dice = 1;
    while(cin >> row >> col) {
        if(!row && !col) break;
        cout << "Throw " << dice++ << endl;
        vector <int> ans;
        char ch;
        int **grid;
        grid = new int*[col];
        for(int i = 0 ;i < col ; i++){
            grid[i] = new int[row];
        }
        for(int i = 0 ; i < col ; i++) {
            for(int j = 0 ; j < row ; j++) {
                cin >> ch;
                if(ch == 'X') {
                    grid[i][j] = 1;
                }else if(ch == '*') {
                    grid[i][j] = 2;
                }else{
                    grid[i][j] = 0;
                }
            }
        }
        for(int i = 0 ; i < col ; i++) {
            for(int j = 0 ; j < row ; j++){
                if(grid[i][j] == 1) {
                    countans = 0;
                    check(grid, i, j);
                    ans.push_back(countans);
                }
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0 ; i < ans.size() ; i++) {
            if(i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl << endl;
        for(int i = 0 ; i < col ; i++) {
            delete [] grid[i];
        }
        delete [] grid;
    }
}
