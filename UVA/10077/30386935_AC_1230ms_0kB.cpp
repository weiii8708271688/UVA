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

void sterndif(int now, vector <stern_> stern) {
    double real = stern[now].son/stern[now].mom;
    double temp = s/m;
    if(temp == real) return;
    if(temp > real) {
        ans += 'R';
        stern_ temp;
        temp.mom = stern[now].mom + stern[now+1].mom;
        temp.son = stern[now].son + stern[now+1].son;
        stern.insert(stern.begin() + now + 1, temp);
        sterndif(now+1, stern);
    }else{
        ans += 'L';
        stern_ temp;
        temp.mom = stern[now].mom + stern[now-1].mom;
        temp.son = stern[now].son + stern[now-1].son;
        stern.insert(stern.begin() + now, temp);
        sterndif(now, stern);
    }
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
        sterndif(1, stern);
        cout << ans << endl;
    }
}//
