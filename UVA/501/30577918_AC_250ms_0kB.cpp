#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

int M,N;
int now;
int printnum;
int countnum;
vector <long long> ans;

void output(long long tobeadd, const int* tobeprint) {
    int L = 0, R = now, M;
    while(L!=R) {
        M = (L+R)/2;
        if(tobeadd > ans[M]) {
            L = M+1;
        }
        if(tobeadd <= ans[M]) {
            R = M;
        }
    }
    //cout << " L " << L << " R " << R << endl;
    ans.insert(ans.begin()+L, tobeadd);
    now++;
    while(tobeprint[printnum] == now && printnum < N) {
        printnum++;
        cout << ans[countnum++] << endl;
    }
}


int main() {
    int datacase;
    cin >> datacase;
    while(datacase--) {
        now = 0;
        printnum = 0;
        countnum = 0;
        ans.clear();
        cin >> M >> N;
        long long tobeadd[M];
        int* tobeprint = new int[N];
        for(int i = 0  ; i < M ; i++) {
            cin >> tobeadd[i];
        }
        for(int i = 0 ; i < N ; i++) {
            cin >> tobeprint[i];
        }
        for(int i = 0 ; i < M ; i++) {
            output(tobeadd[i], tobeprint);
        }
        if(datacase) {
            cout << endl;
        }
    }
}
