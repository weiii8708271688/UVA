#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;



int main(){
    int n;
    cin >> n;
    while(n--) {
        vector <int> coutnum;
        coutnum.clear();
        int col, row;
        char ch;
        cin >> row >> col;
        int ans[col][row];
        for(int i = 0 ; i < col; i++) {
            for(int j = 0 ; j < row ; j++) {
                cin >> ch;
                int temp = ch;
                ans[i][j] = temp;
            }
        }
        int measer[col] = {0};
        for(int i = 0 ; i < col ; i++) {
            for(int j = 0 ; j < row ; j++) {
                for(int k = j+1 ; k < row ; k++) {
                    if(ans[i][j] > ans[i][k]){
                        measer[i]++;
                    }
                }
            }
        }
        //for(int i = 0 ; i < col ; i++) {
            //cout << "measer[" << i << "] == " << measer[i] << endl;
        //}
        for(int i = 0 ; i < col ; i++) {
            int minnum = 0;
            for(int j = 0 ; j < col ; j++) {
                if(measer[j] >= measer[minnum]) {
                    //cout << "brfore minnum == " << minnum << "when i == " << i << endl;
                    minnum = j;
                    //cout << "now minnum == " << minnum << "when i == " << i << endl;
                }
            }
            coutnum.push_back(minnum);
            //cout << "coutnum[" << i << "] == " << coutnum[i] << " measer[" << coutnum[i] << "] == " << measer[coutnum[i]] << endl;
            measer[minnum] = -1;
        }
        for(int i = col-1 ; i >= 0 ; i--) {
            for(int j = 0 ; j < row ; j++) {
                char ch = ans[coutnum[i]][j];
                cout << ch;
            }
            cout << endl;
        }
        if(n != 0)
        cout << endl;
    }
}
