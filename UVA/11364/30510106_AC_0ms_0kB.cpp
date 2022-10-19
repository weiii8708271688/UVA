#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;



int main() {
    int n;
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        int dot[num];
        for(int i = 0 ; i < num ; i++) {
            cin >> dot[i];
        }
        sort(dot, dot+num);
        cout << (dot[num-1] - dot[0])*2 << endl;
    }
}
