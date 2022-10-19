#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <limits.h>
using namespace std;

bool grid[26][26];


void dfs(int i, int j) {
    for(int k = 0 ; k < 26 ; k++) {
        if(grid[j][k] && !grid[i][k]) {
            grid[i][k] = true;
            dfs(i, k);
        }
    }
}

int main() {
    int m, n;
    while(cin >> m >> n) {
        for(int i = 0 ; i < 26 ; i++) {
            for(int j = 0 ; j < 26 ; j++) {
                if(i == j) {
                    grid[i][j] = true;
                }else{
                    grid[i][j] = false;
                }
            }
        }
        for(int i = 0 ; i < m ; i++) {
            char ch;
            cin >> ch;
            int temp = ch - 'a';
            cin >> ch;
            int temp2 = ch - 'a';
            grid[temp][temp2] = true;
        }
        for(int i = 0 ; i < 26 ; i++) {
            for(int j = 0; j < 26 ; j++) {
                if(i != j && grid[i][j]) {
                    grid[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        /*for(int i = 0 ; i < 26 ; i++) {
            cout << (char)(i+'a') << " match whih ";
            for(int j = 0 ; j < 26 ; j++) {
                if(grid[i][j]) {
                    cout << (char)(j+'a') << " ";
                }
            }
            cout << endl;
        }*/
        for(int i = 0 ; i < n ; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if(s1.size() != s2.size()) {
                cout << "no" << endl;
                continue;
            }
            bool b = true;
            for(int j = 0 ; j < s1.size() ; j++) {
                int temp = s1[j] - 'a';
                int temp2 = s2[j] - 'a';
                if(!grid[temp][temp2]) {
                    b = false;
                    break;
                }
            }
            if(b) {
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
}


