#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

struct vector_{
    double x,y;
};

vector_ point[4];

void s(int a, int b) {
    vector_ temp;
    temp.x = point[a].x;
    temp.y = point[a].y;
    point[a].x = point[b].x;
    point[a].y = point[b].y;
    point[b].x = temp.x;
    point[b].y = temp.y;
}

int main() {
    vector_ ans;
    while(cin >> point[0].x >> point[0].y) {
        for(int i = 1 ; i < 4 ; i++) {
            cin >> point[i].x >> point[i].y;
        }
        if(point[1].x == point[2].x && point[1].y == point[2].y) {
            s(0,1);
        }
        if(point[1].x == point[3].x && point[1].y == point[3].y) {
            s(0,1);
            s(2,3);
        }
        if(point[0].x == point[3].x && point[0].y == point[3].y) {
            s(2,3);
        }
        ans.x = point[1].x + (point[3].x - point[0].x);
        ans.y = point[3].y + (point[1].y - point[0].y);
        cout << fixed << setprecision(3) << ans.x << " " << ans.y << endl;
    }
}
