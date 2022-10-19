#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int n1, n2, count = 1;
    int tower[101][101] = {0};
    while(cin >> n1 >> n2) {
        if(!n1 && !n2) break;
        cout << "Twin Towers #" << count++ << endl;
        for(int i = 1 ; i <= n1 ; i++) {
            cin >> tower[0][i];
        }
        for(int i  = 1 ; i <= n2 ; i++) {
            cin >> tower[1][i];
        }
        int anssheet[n1+1][n2+1];
        for(int i = 0 ; i <= n1 ; i++) {
            for(int j = 0 ; j <= n2 ; j++) {
                anssheet[i][j] = 0;
            }
        }
        for(int i = 1 ; i <= n1 ; i++) {
            for(int j = 1 ; j <= n2 ; j++) {
                if(tower[0][i] == tower[1][j]) {
                    anssheet[i][j] = anssheet[i-1][j-1]+1;
                }else{
                    anssheet[i][j] = max(anssheet[i-1][j], anssheet[i][j-1]);
                }
            }
        }
        cout << "Number of Tiles : " << anssheet[n1][n2]<<endl << endl;
    }

}
