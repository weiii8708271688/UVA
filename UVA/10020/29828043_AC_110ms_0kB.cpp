#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        bool canreach = true;
        int goal, l, r;
        vector <int> L,R;
        L.clear();
        R.clear();
        cin >> goal;
        while(cin >> l >> r) {
            if(!l && !r) break;
            L.push_back(l);
            R.push_back(r);
        }
        int left = 0, right = 0, tempright = goal;
        vector <int> answer;
        answer.clear();
        while(right < goal) {
            //cout << "now left == " << left << endl;
            //cout << "now right == " << right << endl;
            if(tempright == right) {
                canreach = false;
                break;
            }
            tempright = right;
            int max = 0;
            int ans;
            for(int i = 0 ; i < R.size() ; i++) {
                if(L[i] <= left && R[i] > right) {
                    //cout << i << " in secend round" << endl;
                    if(R[i] - right > max) {
                        max = R[i]-right;
                        ans = i;
                    }
                    if(R[i] - right == max) {
                        if(L[i] < L[ans]) {
                            ans = i;
                        }
                    }
                }
            }
            answer.push_back(ans);
            if(max) {
                left = R[ans];
                right = R[ans];
            }
        }
        if(canreach) {
            cout << answer.size() << endl;
            for(int i = 0 ; i < answer.size() ; i++) {
                cout << L[answer[i]] << " " << R[answer[i]] << endl;
            }
        }else {
            cout << "0" << endl;
        }
        if(n) {
            cout << endl;
        }
    }
}
