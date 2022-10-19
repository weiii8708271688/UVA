#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

int c,row,col,n;

bool check(int x, int y, char** grid, string s) {
    if(s.size() == 1) return true;
    for(int i = -1 ; i <= 1 ; i++) {
        for(int j = -1 ; j <= 1 ; j++) {
            //cout << "i == " << i << " j == " << j << endl;
            if(i==0 && j==0) continue;
            int k;
            for(k = 1 ; k < s.size() ; k++) {
                if(x+k*i < 0 || x+k*i == row || y+k*j < 0 || y+k*j == col) break;
                if(grid[x+k*i][y+k*j] != s[k]) break;
                //cout << "no.2 " << x+k*i << " " << y+k*j << " == " << grid[x+k*i][y+k*j] <<  endl;
            }
            //cout << "k"  << k << endl;
            if(k == s.size()) return true;
        }
    }
    return false;
}


int main() {
    cin >> c;
    while(c--) {
        cin >> row >> col;
        char **grid = new char*[row];
        for(int i = 0 ; i < row ; i++) {
            grid[i] = new char[col];
        }
        char ch;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                cin >> ch;
                grid[i][j] = tolower(ch);
            }
        }
        //cout << endl << endl;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                //cout << grid[i][j];
            }
            //cout << endl;
        }
        cin >> n;
        string s;
        getline(cin, s);
        for(int k = 0 ; k < n ; k++) {
            getline(cin,s);
            for(int i = 0 ; i < s.size() ; i++) {
                s[i] = tolower(s[i]);
            }
            //cout << s << endl;
            bool ans = false;
            int ansrow, anscol;
            for(int i = 0 ; i < row ; i++) {
                if(ans) break;
                for(int j = 0 ; j < col ; j++) {
                    if(grid[i][j] == s[0]) {
                        //cout << i << " " << j << endl;
                        ans = check(i,j, grid, s);
                        if(ans) {
                        cout << i+1 << " " << j+1 << endl;
                        break;
                        }
                    }
                }
            }
        }
        if(c) cout << endl;
    }
}
