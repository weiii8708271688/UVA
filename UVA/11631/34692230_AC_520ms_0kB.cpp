#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <climits>
using namespace std;




int main() {
    int m, n;
    while(cin >> m >> n) {
        if(!m && !n) break;
        vector <pair<int, int>> G[m];
        int sum = 0, cost = 0;
        while(n--) {
            int a, b, meter;
            cin >> a >> b >> meter;
            sum += meter;
            G[a].push_back(make_pair(b, meter));
            G[b].push_back(make_pair(a, meter));
        }

        int dis[m];
        for(int i = 0 ; i < m ; i++) dis[i] = INT_MAX;
        dis[0] = 0;
        bool visited[m] = {0};




        for(int i = 0 ; i < m ; i++) {
            int visit, dis_min = INT_MAX;
            for(int j = 0 ; j < m ; j++) {
                if(!visited[j] && dis[j] < dis_min) {
                    dis_min = dis[j];
                    visit = j;
                }
            }

            visited[visit] = true;
            cost += dis[visit];
            for(int j = 0 ; j < G[visit].size() ; j++) {
                int cur = G[visit][j].first;
                if(!visited[cur]) {
                    if(G[visit][j].second < dis[cur]) {
                        dis[cur] = G[visit][j].second;
                    }
                }
            }
        }
        cout << sum - cost << endl;
    }
}
