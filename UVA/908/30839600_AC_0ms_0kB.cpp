#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;
int n = 0, k = 0, m = 0;
struct road_{
    int a,b,cost;
}road[1000010];


bool comp(road_ a, road_ b) {
    return a.cost < b.cost;
}


int main() {
    while(cin >> n) {
        if(k) cout << endl;
        int ans = 0;
        for(int i = 1 ; i < n ; i++) {
            int temp;
            cin >> temp >> temp >> temp;
            ans+=temp;
        }
        cout << ans << endl;
        ans = 0;
        cin >> k;
        for(int i = 0 ; i < k ; i++) {
            cin >> road[i].a >> road[i].b >> road[i].cost;
        }
        cin >> m;
        for(int i = k ; i < k+m ; i++) {
            cin >> road[i].a >> road[i].b >> road[i].cost;
        }
        sort(road, road + m + k, comp);
        int count = 2;
        int hadbeen[n+1] = {0};
        hadbeen[road[0].a] = true;
        hadbeen[road[0].b] = true;
        ans+=road[0].cost;
        while(count != n) {
            for(int i = 1 ; i < m+k ; i++) {
                if(hadbeen[road[i].a] && !hadbeen[road[i].b]) {
                    count++;
                    hadbeen[road[i].b] = true;
                    ans += road[i].cost;
                    break;
                }else if(!hadbeen[road[i].a] && hadbeen[road[i].b]) {
                    count++;
                    hadbeen[road[i].a] = true;
                    ans += road[i].cost;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
