#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

//not me

struct work{
    double t;
    double s;
    int index;
};

bool cmp(work a, work b) {
    return a.s/a.t > b.s/b.t;
}


int main() {
    int n;
    cin >> n;
    while(n--) {
        int c;
        cin >> c;
        work shoe[c];
        for(int i = 0 ; i < c ; i++) {
            cin >> shoe[i].t >> shoe[i].s;
            shoe[i].index = i+1;
        }
        sort(shoe, shoe+c, cmp);
        for(int i = 0 ; i < c ; i++) {
            cout << shoe[i].index;
            if(i < c-1) cout << " ";
        }
        cout << endl;
        if(n) cout << endl;
    }
}


