#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    char grid[2][6][5];
    int n;
    cin >> n;
    while(n--) {
        vector <char> same[5];
        int k;
        cin >> k;
        for(int i = 0 ; i < 2 ; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                for(int z = 0 ; z < 5 ; z++) {
                    cin >> grid[i][j][z];
                }
            }
        }
        for(int i = 0 ; i < 5 ; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                for(int h = 0 ; h < 6 ; h++){
                    if(grid[0][j][i] == grid[1][h][i]) {
                        bool doit = true;
                        for(int z = 0 ; z < same[i].size() ; z++) {
                            if(same[i][z] == grid[0][j][i]) {
                                doit = false;
                            }
                        }
                        if(doit){
                            same[i].push_back(grid[0][j][i]);
                            grid[1][h][i] = ' ';
                            break;
                        }
                    }
                }
            }
        }

        int allposs = 1;
        int ansSize[5];
        for(int i = 0 ; i < 5 ; i++) {
            allposs*=same[i].size();
            ansSize[i] = same[i].size();
            sort(same[i].begin(),same[i].end());
        }
        /*for(int i = 0 ; i < 5 ; i++) {
            cout << "same "  << i << " == ";
            for(int j = 0 ; j < same[i].size() ; j++) {
                cout << same[i][j] << " ";
            }
            cout << endl;
        }*/
        int ans[5] = {0};
        if(allposs < k) {
            cout << "NO" << endl;
        }else{
            while(--k) {
                ans[4]++;
                int now = 4;
                while(ans[now] == ansSize[now]) {
                    ans[now-1]++;
                    ans[now] = 0;
                    now--;
                }
            }
            for(int i = 0 ; i < 5 ; i++) {
                cout << same[i][ans[i]];
            }
            cout << endl;
        }
    }
}
