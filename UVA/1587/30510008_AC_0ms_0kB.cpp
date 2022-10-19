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
    int a[6], b[6];
    int temp[2];
    while(cin >> a[0] >> b[0]) {
        for(int i = 1 ; i < 6  ; i++) {
            cin >> a[i] >> b[i];
        }
        for(int i = 0 ; i < 6 ; i++) {
            if(a[i] < b[i]) {
                int temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        }
        int count = 0;
        for(int i = 0 ; i < 6 ; i++) {
            for(int j = i+1 ; j < 6 ; j++) {
                if(a[i] == a[j] && b[i] == b[j] && a[j]) {
                    count++;
                    a[j] = 0;
                    b[j] = 0;
                    break;
                }
            }
        }
        for(int i = 0 ; i < 6 ; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                if(a[i] > a[j]) {
                    int temp[2];
                    temp[0] = a[i];
                    temp[1] = b[i];
                    a[i] = a[j];
                    b[i] = b[j];
                    a[j] = temp[0];
                    b[j] = temp[1];
                }
                if(a[i] == a[j]) {
                    if(b[i] > b[j]) {
                        int temp[2];
                    temp[0] = a[i];
                    temp[1] = b[i];
                    a[i] = a[j];
                    b[i] = b[j];
                    a[j] = temp[0];
                    b[j] = temp[1];
                    }
                }
            }
        }
        bool q = true;
        if(count != 3) {
            q = false;
        }
        if(a[0] != a[1] || b[0] != a[2] || b[1] != b[2]) {
            q = false;
        }
        if(q) {
            cout << "POSSIBLE" << endl;
        }else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
