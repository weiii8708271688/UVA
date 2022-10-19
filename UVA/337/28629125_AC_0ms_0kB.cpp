#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

bool is_num(char ch) {
    return (ch >= '0' && ch <= '9');
}

int main() {
	int n;
	int casecount = 0;
	string s;
	char grid [10][10];
	while(cin >> n) {
        if(!n) break;
        int row = 0, col = 0;
        casecount++;
        cout << "Case " << casecount << endl;
        bool insert_ = false;
        for(int i = 0  ; i < 10 ; i++) {
            for(int j = 0 ; j < 10 ; j++) {
                grid[i][j] = ' ';
            }
        }
        getline(cin, s);
        while(n--) {
            getline(cin, s);
            for(int i = 0 ; i < s.size() ; i++) {
                if(s[i] == '^') {
                    switch(s[i+1]) {

                        case '^' : if(insert_) {
                                        for(int j = 8 ; j >= col ; j--) {
                                            grid[row][j+1] = grid[row][j];
                                        }
                                    }
                                    grid[row][col] = '^';
                                    col++;break;

                        case 'b' : col = 0;break;

                        case 'c' : for(int k = 0  ; k < 10 ; k++) {
                                        for(int j = 0 ; j < 10 ; j++) {
                                            grid[k][j] = ' ';
                                        }
                                    }break;

                        case 'd' : if(row < 9) {
                                        row++;
                                    }break;

                        case 'e' : for(int j = col+1 ; j < 10 ; j++) {
                                        grid[row][j] = ' ';
                                    }break;

                        case 'h' : row = 0;
                                    col = 0;break;

                        case 'i' : insert_ = true;break;

                        case 'l' : if(col > 0) {
                                        col--;
                                    }break;

                        case 'o' : insert_ = false;break;

                        case 'r' : if(col < 9) {
                                        col++;
                                    }break;

                        case 'u' : if(row > 0) {
                                        row--;
                                    }break;
                    }
                    if( is_num(s[i+1]) ) {
                        row = s[i+1] - '0';
                        col = s[i+2] - '0';
                        i++;
                    }
                    i++;
                }
                else{
                    if(insert_) {
                        for(int j = 8 ; j >= col ; j--) {
                            grid[row][j+1] = grid[row][j];
                        }
                    }
                    grid[row][col] = s[i];
                    if(col < 9) {
                        col++;
                    }
                }
            }
        }
        cout << "+----------+" << endl;
        for(int i = 0  ; i < 10 ; i++) {
            cout << "|";
            for(int j = 0 ; j < 10 ; j++) {
                cout << grid[i][j];
            }
            cout << "|";
            cout << endl;
        }
        cout << "+----------+" << endl;
	}
}
