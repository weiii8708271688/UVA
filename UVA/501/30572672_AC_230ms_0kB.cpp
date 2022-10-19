#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

int now;
int printnum;
int countnum;
vector <long long> ans;

void output(long long tobeadd, const int* tobeprint) {
    //cout << "tobeadd == " << tobeadd << endl;
    if (now == 0) {
        ans.push_back(tobeadd);
    }
    else {
        if (tobeadd <= ans[0]) {
            ans.insert(ans.begin(), tobeadd);
        }
        else if (tobeadd >= ans[now - 1]) {
            ans.push_back(tobeadd);
        }
        else {
            int start = 0, end = now - 1, mid = (start + end) / 2;
            while (start < end) {
                mid = (start + end) / 2;
                //cout << "start == " << start << " " << " end == " << end << " mid == " << mid << endl;
                if (tobeadd > ans[mid]) {
                    start = mid+1;
                }
                if (tobeadd < ans[mid]) {
                    end = mid-1;
                }
                if (tobeadd == ans[mid]) {
                    break;
                }
                //cout << "after start == " << start << " " << " end == " << end << " mid == " << mid << endl;
            }
            mid = (start + end) / 2;
            //cout << "start == " << start << " " << " end == " << end << endl;
            if (tobeadd < ans[mid]) {
                ans.insert(ans.begin() + mid, tobeadd);
            }
            else {
                ans.insert(ans.begin() + mid + 1, tobeadd);
            }
        }
    }
    now++;
    while (tobeprint[printnum] == now) {
        printnum++;
        cout << ans[countnum++] << endl;
    }
}


int main() {
    int datacase;
    cin >> datacase;
    while (datacase--) {
        now = 0;
        printnum = 0;
        countnum = 0;
        ans.clear();
        int M, N;
        cin >> M >> N;
        long long *tobeadd = new long long [M]();
        int* tobeprint = new int[N];
        for (int i = 0; i < M; i++) {
            cin >> tobeadd[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> tobeprint[i];
        }
        for (int i = 0; i < M; i++) {
            output(tobeadd[i], tobeprint);
        }
        if(datacase) {
            cout << endl;
        }
    }
}
