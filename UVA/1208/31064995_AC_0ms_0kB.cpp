#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <limits.h>
#include <ctime>
using namespace std;

struct path{
    int a,b,val;
};

bool cmp(path a, path b) {
    return a.val < b.val;
}


int main() {
    int c;
    cin >> c;
    for(int k = 1 ; k <= c ; k++) {
        vector <path> allpath, ans;
        cout << "Case " << k << ":" << endl;
        int num;
        cin >> num;
        int grid[num][num];
        for(int i = 0 ; i < num ; i++) {
            cin >> grid[i][0];
            for(int j = 1 ; j < num ; j++) {
                char ch;
                cin >> ch >> grid[i][j];
            }
        }
        path temp;
        for(int i = 0 ; i < num ; i++) {
            for(int j = num-1 ; j > i ; j--) {
                if(grid[i][j]) {
                    temp.a = i;
                    temp.b = j;
                    temp.val = grid[i][j];
                    allpath.push_back(temp);
                }
            }
        }
        sort(allpath.begin(), allpath.end(), cmp);
        bool visited[num] = {0};
        visited[allpath[0].a] = true;
        visited[allpath[0].b] = true;
        ans.push_back(allpath[0]);
        for(int i = 1 ; i < num ; i++) {
            for(int j = 1 ; j < allpath.size() ; j++) {
                if(!visited[allpath[j].a] && visited[allpath[j].b]) {
                    visited[allpath[j].a] = true;
                    ans.push_back(allpath[j]);
                    break;
                }else if(visited[allpath[j].a] && !visited[allpath[j].b]) {
                    visited[allpath[j].b] = true;
                    ans.push_back(allpath[j]);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0 ; i < ans.size() ; i++) {
            char ch1 = 'A'+ans[i].a;
            char ch2 = 'A'+ans[i].b;
            cout << ch1 << "-" << ch2 << " " << ans[i].val << endl;
        }
    }
}
