#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int sizeofstone;

struct coor{
    int x;
    int y;
};

double distence(coor boy, coor girl) {
    return sqrt(pow(boy.x - girl.x, 2) + pow(boy.y - girl.y, 2));
}

double min(double a, double b) {
    if(a > b) {
        return b;
    }
    return a;
}

double max(double a, double b) {
    if(a > b) {
        return a;
    }
    return b;
}

int main() {
    int count = 1, n;
    while(cin >> sizeofstone) {
        if(!sizeofstone) break;
        cout << "Scenario #" << count++ << endl;
        coor stone[sizeofstone];
        double dis[sizeofstone][sizeofstone];
        for(int k = 0 ; k < sizeofstone ; k++) {
            cin >> stone[k].x >> stone[k].y;
        }

        for(int i = 0 ; i < sizeofstone ; i++) {
            for(int j = 0 ; j < sizeofstone ; j++) {
                dis[i][j] = distence(stone[i], stone[j]);
            }
        }
        for(int k = 0 ; k < sizeofstone ; k++) {
            for(int i = 0 ; i < sizeofstone ; i++) {
                for(int j = 0 ; j < sizeofstone ; j++) {
                    dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
                }
            }
        }


        /*for(int i = 0 ; i < sizeofstone ; i++) {
            for(int j = 0 ; j < sizeofstone ; j++) {
                cout << fixed << setprecision(3) << dis[i][j] << " ";
            }
            cout <<endl;
        }
        */

        cout << "Frog Distance = " << fixed << setprecision(3) << dis[0][1] << endl << endl;
    }
}

