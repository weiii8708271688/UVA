#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

double s,m;
string ans;

struct stern_{
    double mom,son;
};



void sterndif(vector <stern_> stern, double temp) {
    double real = stern[1].son/stern[1].mom;
    if(temp == real) return;
    if(temp > real) {
        ans += 'R';
        stern[0].mom = stern[1].mom;
        stern[0].son = stern[1].son;
    }else{
        ans += 'L';
        stern[2].mom = stern[1].mom;
        stern[2].son = stern[1].son;
    }
    stern[1].mom = stern[0].mom + stern[2].mom;
    stern[1].son = stern[0].son + stern[2].son;
    sterndif(stern, temp);
}

int main() {
    while(cin >> s >> m) {
        if(s == 1 && m == 1) break;
        ans = "";
        vector <stern_> stern(3);
        stern[0].mom = 1;
        stern[0].son = 0;
        stern[1].mom = 1;
        stern[1].son = 1;
        stern[2].mom = 0;
        stern[2].son = 1;
        sterndif(stern, s/m);
        cout << ans << endl;
    }
}
