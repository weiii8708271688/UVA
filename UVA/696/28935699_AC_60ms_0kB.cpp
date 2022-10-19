#include <vector>
#include<iostream>
#include<cmath>
using namespace std ;

int main(){
    int col, row;
    while(cin >> row >> col) {
        if(!row && !col) break;
        int ans = 0;
        int rowcout = row, colcout = col;
        if(row > col) {
            int temp = row;
            row = col;
            col = temp;
        }
        if(row == 1) {
            ans = col;
        }else if(row == 2) {
            ans = col/4*4;
            if(col%4 == 1) {
                ans+=2;
            }else if(col%4 == 2  || col%4 == 3) {
                ans+=4;
            }
        }else{
            if(row%2) {
                ans = (col+1)/2;
                ans+=(row-1)*col/2;
            }else{
                ans = row*col/2;
            }
        }
        cout << ans << " knights may be placed on a "  << rowcout << " row " << colcout << " column board." <<endl;
    }
}
