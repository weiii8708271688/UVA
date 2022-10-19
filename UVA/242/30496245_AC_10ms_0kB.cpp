#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

struct stamp_{
    int nums;
    int answer[10];
    int stampmax;
};
//好難喔


int main() {
    int acc, cas;
    while(cin >> acc) {
        if(!acc) break;
        stamp_ ans;
        int Max = -1;
        cin >> cas;
        int dp[1001];
        while(cas--) {
            int num, valuemax = -1;
            cin >> num;
            int value[num];
            for(int i = 1 ; i < 1001 ; i++) dp[i] = 0;
            dp[0] = 1;
            for(int i = 0 ; i < num ; i++) {
                cin >> value[i];
                if(value[i] > valuemax) valuemax = value[i];
            }
            for(int i = 0 ; i < num ; i++) {
                for(int j = 0 ; j < 1001 ; j++) {
                    if(dp[j] <= acc && dp[j]) {
                        if(dp[j+value[i]] == 0 || dp[j] + 1 < dp[j+value[i]]) { //如果發現只要多加一個郵票就可以花比之前要的郵票數更少 那就選擇只加一個郵票並更新
                            dp[j+value[i]] = dp[j] + 1;
                        }
                    }
                }
            }
            int tempans;
            for(int i = 0 ; i < 1001 ; i++) {
                if(!dp[i]) {
                    tempans = i-1;
                    break;
                }
            }
            if(tempans > Max) {
                Max = tempans;
                ans.nums = num;
                ans.stampmax = valuemax;
                for(int i = 0 ; i < num ; i++) ans.answer[i] = value[i];
            }
            if(tempans == Max) {
                if(ans.nums == num) {
                    if(value[num-1] < ans.stampmax) {
                        Max = tempans;
                        ans.nums = num;
                        ans.stampmax = valuemax;
                        for(int i = 0 ; i < num ; i++) ans.answer[i] = value[i];
                    }
                }
                if(num < ans.nums) {
                    Max = tempans;
                    ans.nums = num;
                    ans.stampmax = valuemax;
                    for(int i = 0 ; i < num ; i++) ans.answer[i] = value[i];
                }
            }
        }
        cout << "max coverage =" << setw(4) << Max << " :";
        for(int i = 0 ; i < ans.nums ; i++) {
            cout << setw(3) << ans.answer[i];
        }
        cout << endl;
    }
}
