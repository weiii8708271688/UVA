#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <ctime>
#include <queue>
using namespace std;

struct point{
    int x, y;
};

struct edge{
    point a, b;
    double dis;
};


double distence(point a, point b) {
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}



int main() {
    int t;
ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    for(int cas = 1 ; cas <= t ; cas++) {
        int n, r;
        cin >> n >> r;
        double road = 0, train = 0;
        point city[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> city[i].x >> city[i].y;
        }
        vector <vector<int>> states;
        bool state[n] = {0};

        for(int i = 0 ; i < n ; i++) {
            if(!state[i]) {
                state[i] = true;
                vector <int> temp;
                temp.push_back(i);
                queue <int> q;
                q.push(i);
                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    for(int j = 0 ; j < n ; j++) {
                        if(!state[j]) {
                            if(distence(city[cur], city[j]) <= r) {
                                state[j] = true;
                                temp.push_back(j);
                                q.push(j);
                            }
                        }
                    }
                }
                states.push_back(temp);
            }
        }

        for(int i = 0 ; i < states.size() ; i++) {
            bool visited[n] = {0};
            double dis[n];
            for(int j = 0 ; j < n ; j++) dis[j] = 1000000;
            dis[states[i][0]] = 0;
            for(int j = 0 ; j < states[i].size() ; j++) {
                int visit;
                double dismin = 1000000;
                for(int k = 0 ; k < states[i].size() ; k++) {
                    int cur = states[i][k];
                    if(!visited[cur] && dis[cur] < dismin) {
                        dismin = dis[cur];
                        visit = cur;
                    }
                }
                visited[visit] = true;
                road += dis[visit];
                for(int k = 0 ; k < states[i].size() ; k++) {
                    int cur = states[i][k];
                    if(!visited[cur]) {
                        if(distence(city[visit], city[cur]) < dis[cur]) {
                            dis[cur] = distence(city[visit], city[cur]);
                        }
                    }
                }

            }
        }
        double state_dis[states.size()][states.size()];

        for(int i = 0 ; i < states.size() ; i++) {
            for(int j = 0 ; j < states.size() ; j++) {
                state_dis[i][j] = 100000;
            }
        }

        for(int i = 0 ; i < states.size() ; i++) {
            for(int j = 0 ; j < states.size() ; j++) {
                for(int k = 0 ; k < states[i].size() ; k++) {
                    for(int l = 0 ; l < states[j].size() ; l++) {
                        state_dis[i][j] = min(state_dis[i][j], distence(city[states[i][k]], city[states[j][l]]));
                    }
                }
            }
        }

        bool visited[states.size()] = {0};
        double dis[states.size()];
        for(int j = 0 ; j < states.size() ; j++) dis[j] = 1000000;
        dis[0] = 0;
        for(int j = 0 ; j < states.size() ; j++) {
            int visit;
            double dismin = 1000000;
            for(int k = 0 ; k < states.size() ; k++) {
                int cur = k;
                if(!visited[cur] && dis[cur] < dismin) {
                    dismin = dis[cur];
                    visit = cur;
                }
            }
            visited[visit] = true;
            train += dis[visit];
            for(int k = 0 ; k < states.size() ; k++) {
                int cur = k;
                if(!visited[cur]) {
                    if(state_dis[visit][cur] < dis[cur]) {
                        dis[cur] = state_dis[visit][cur];
                    }
                }
            }
        }




        cout << "Case #" << cas << ": " << states.size() << " " << (int)(road+0.5) << " " << (int)(train+0.5) << endl;


//        for(int i = 0 ; i < states.size() ; i++) {
//            for(int j = 0 ; j < states[i].size() ; j++) {
//                cout << states[i][j] << " ";
//            }
//            cout << "are connect" << endl;
//        }

    }
}
