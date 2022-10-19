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

int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};
string* s;

void remove_0(int row, int col, int h, int w) {
    s[row][col] = '2';
    for(int i = 0 ; i < 4 ; i++) {
        int trow = row + drow[i];
        int tcol = col + dcol[i];
        if(trow > h || tcol > w || trow < 0 || tcol < 0) continue;
        if(s[trow][tcol] == '0') {
            remove_0(trow, tcol, h, w);
        }
    }
}

int floodfill(int row, int col, int h, int w) {
    int ans = 0;
    s[row][col] = '3';
    for(int i = 0 ; i < 4 ; i++) {
        int trow = row + drow[i];
        int tcol = col + dcol[i];
        if(trow > h || tcol > w || trow < 0 || tcol < 0) continue;
        if(s[trow][tcol] == '0') {
            remove_0(trow, tcol, h, w);
            ans++;
        }else if(s[trow][tcol] == '1') {
            ans += floodfill(trow, tcol, h, w);
        }
    }
    return ans;
}


int main() {
    int h, w, t = 1;
    while(cin >> h >> w) {
        if(!h && !w) break;
        s = new string[h+2];
        cin.ignore();
        string temp;
        s[0] += "0";
        s[h+1] += "0";
        for(int i = 0 ; i < w ; i++) {
            s[0] += "0000";
            s[h+1] += "0000";
        }
        s[0] += "0";
        s[h+1] += "0";
        for(int i = 1 ; i <= h ; i++) {
            getline(cin, temp);
            s[i] += "0";
            for(int j = 0 ; j < temp.size() ; j++) {
                char ch;
                ch = temp[j];
                switch(ch) {
                    case '0': s[i] += "0000"; break;
                    case '1': s[i] += "0001"; break;
                    case '2': s[i] += "0010"; break;
                    case '3': s[i] += "0011"; break;
                    case '4': s[i] += "0100"; break;
                    case '5': s[i] += "0101"; break;
                    case '6': s[i] += "0110"; break;
                    case '7': s[i] += "0111"; break;
                    case '8': s[i] += "1000"; break;
                    case '9': s[i] += "1001"; break;
                    case 'a': s[i] += "1010"; break;
                    case 'b': s[i] += "1011"; break;
                    case 'c': s[i] += "1100"; break;
                    case 'd': s[i] += "1101"; break;
                    case 'e': s[i] += "1110"; break;
                    case 'f': s[i] += "1111"; break;
                }
            }
            s[i] += "0";
        }
        bool f = true;
        /*
        for(int k = 0 ; k <= h+1 ; k++) {
            cout << s[k] << endl;
        }*/
        priority_queue <char, vector<char>, greater<char>> output;
        for(int i = 1 ; i <= h ; i++) {
            for(int j = 0 ; j < s[i].size() ; j++) {
                if(s[i][j] == '1') {
                    int ans = floodfill(i, j, h+1, w*4+2);
                    if(f) {
                        ans--;
                        f = false;
                    }
                    switch(ans) {
                        case 0: output.push('W'); break;
                        case 1: output.push('A'); break;
                        case 2: output.push('K'); break;
                        case 3: output.push('J'); break;
                        case 4: output.push('S'); break;
                        case 5: output.push('D'); break;
                    }/*
                    for(int k = 0 ; k <= h+1 ; k++) {
                        cout << s[k] << endl;
                    }*/
                }
            }
        }
        cout << "Case " << t++ << ": ";
        while(!output.empty()) {
            cout << output.top();
            output.pop();
        }
        cout << endl;
        delete []s;
    }
}
