#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int cas, n, t, c;
    cin >> cas;
    while(cas--) {
        cin >> n;
        int matrix[n][n];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> matrix[i][j];
            }
        }
        int temp, row;
        row = 0;
        temp = n;
        while(true) {
            if(temp == -1 || !temp) break;
            cin >> t;
            while(t--) {
                vector <int>me;
                me.clear();
                cin >> c;
                if(c == 1) {
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = 0 ; j < temp ; j++) {
                                me.push_back(matrix[row+i][row+j]);
                            }
                        }else {
                            me.push_back(matrix[row+i][row]);
                            me.push_back(matrix[row+i][row+temp-1]);
                        }
                    }
                    int count = 0;
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = 0 ; j < temp ; j++) {
                                matrix[row+temp-1-i][row+j] = me[count++];
                            }
                        }else{
                            matrix[row+temp-1-i][row] = me[count++];
                            matrix[row+temp-1-i][row+temp-1] = me[count++];
                        }
                    }
                }else if(c == 2) {
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = 0 ; j < temp ; j++) {
                                me.push_back(matrix[row+i][row+j]);
                            }
                        }else {
                            me.push_back(matrix[row+i][row]);
                            me.push_back(matrix[row+i][row+temp-1]);
                        }
                    }
                    int count = 0;
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = temp-1 ; j >= 0 ; j--) {
                                matrix[row+i][row+j] = me[count++];
                            }
                        }else{
                            matrix[row+i][row+temp-1] = me[count++];
                            matrix[row+i][row] = me[count++];
                        }
                    }
                }else if(c == 4) {
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = 0 ; j < temp ; j++) {
                                me.push_back(matrix[row+i][row+j]);
                            }
                        }else {
                            me.push_back(matrix[row+i][row]);
                            me.push_back(matrix[row+i][row+temp-1]);
                        }
                    }
                    int count = 0;
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = temp-1 ; j >= 0 ; j--) {
                                matrix[row+j][row+temp-1-i] = me[count++];
                            }
                        }else{
                            matrix[row+temp-1][row+temp-1-i] = me[count++];
                            matrix[row][row+temp-1-i] = me[count++];
                        }
                    }
                }else if(c == 3) {
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = 0 ; j < temp ; j++) {
                                me.push_back(matrix[row+i][row+j]);
                            }
                        }else {
                            me.push_back(matrix[row+i][row]);
                            me.push_back(matrix[row+i][row+temp-1]);
                        }
                    }
                    int count = 0;
                    for(int i = 0 ; i < temp ; i++) {
                        if(i == 0 || i == temp-1) {
                            for(int j = 0 ; j < temp ; j++) {
                                matrix[row+j][row+i] = me[count++];
                            }
                        }else{
                            matrix[row][row+i] = me[count++];
                            matrix[row+temp-1][row+i] = me[count++];
                        }
                    }
                }

            }
            temp-=2;
            row++;
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cout << matrix[i][j];
                if(j != n-1) cout << " ";
            }
            cout << endl;
        }
    }
}
