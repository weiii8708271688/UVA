#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;
int c, l, w, k;
struct point{
    int x, y;
};

bool cmp(point a, point b) {
    return a.x < b.x;
}

bool cmp2(point a, point b) {
    return a.y < b.y;
}

point trees[3000];

int solve(int i) {
    int up = w, down = 0, ans = 0;
    for(int j = i+1 ; j < c ; j++) {
        ans = max((trees[j].x-trees[i].x)*(up-down), ans);
        if(trees[j].y > trees[i].y) {
            if(trees[j].y < up) {
                up = trees[j].y;
            }
        }else{
            if(trees[j].y > down) {
                down = trees[j].y;
            }
        }
    }
    return ans;
}



int main() {
    int n;
    cin >> n;
    while(n--) {
        c = 0;
        cin >> l >> w;
        while(cin >> k) {
            if(!k) break;
            point temp;
            if(k == 1) {
                cin >> temp.x >> temp.y;
                trees[c++] = temp;
            }else{
                int dx, dy;
                cin >> temp.x >> temp.y >> dx >> dy;
                for(int i = 0 ; i < k ; i++) {
                    trees[c++] = temp;
                    temp.x += dx;
                    temp.y += dy;
                }
            }
        }
        trees[c++] = {0,0};
        trees[c++] = {0,w};
        trees[c++] = {l,w};
        trees[c++] = {l,0};
        sort(trees, trees+c, cmp);
        int ans = 0;
        for(int i = 0 ; i < c ; i++) {
            ans = max(solve(i), ans);
        }
        for(int i = 0 ; i < c ; i++) {
            swap(trees[i].x, trees[i].y);
        }
        swap(l, w);
        sort(trees, trees+c, cmp);
        for(int i = 0 ; i < c ; i++) {
            ans = max(solve(i), ans);
        }
        cout << ans << endl;
    }
}
