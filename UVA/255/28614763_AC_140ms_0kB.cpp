#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct vector{
    int x;
    int y;
};

int main() {
	vector queen, king, ans;
    int x,y,z;
    while(cin >> x >> y >> z) {
        bool move = true, state = true;
        if(x > 63 || y > 63 || z > 63) {
                state = false;
        }
        king.x = x%8;
        king.y = x/8;
        queen.x = y%8;
        queen.y = y/8;
        ans.x = z%8;
        ans.y = z/8;
        if(x == y) {
            state = false;
        }
        if((ans.x != queen.x && ans.y != queen.y) || y == z) {
            move = false;
        }
        if(king.x == queen.x || king.y == queen.y) {
            if(king.y == queen.y) {
                if(queen.x > king.x) {
                    if(ans.x <= king.x) {
                        move = false;
                    }
                }
                else{
                    if(ans.x >= king.x) {
                        move = false;
                    }
                }
            }
            if(king.x == queen.x) {
                if(queen.y > king.y) {
                    if(ans.y <= king.y) {
                        move = false;
                    }
                }
                else {
                    if(ans.y >= king.y) {
                        move = false;
                    }
                }
            }
        }
        if(move && state){
            if((x == 0 && z == 9) || (x == 7 && z == 14) || (x == 56 && z == 49) || (x == 63 && z == 54)) {
                cout << "Stop" << endl;continue;
            }
            if(ans.x == king.x) {
                if(ans.y == king.y+1 || ans.y == king.y-1){
                    cout << "Move not allowed" << endl;continue;
                }
            }
            if(ans.y == king.y) {
                if(ans.x == king.x-1 || ans.x == king.x+1){
                    cout << "Move not allowed" << endl;continue;
                }
            }
            cout << "Continue" << endl;continue;
        }
        else{
            if(!state) {
                cout << "Illegal state" << endl;continue;
            }
            else{
                cout << "Illegal move" << endl;continue;
            }
        }
    }
}
