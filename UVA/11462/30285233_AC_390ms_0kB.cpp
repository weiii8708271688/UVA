#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        int first = 1;
        int count[100] = {0};
        for(int i = 0 ; i < n ; i++) {
            int temp;
            cin >> temp;
            count[temp]++;
        }
        for(int i = 1 ; i < 100 ; i++) {
            if(count[i]) {
                for(int j = 0 ; j < count[i] ; j++) {
                    if(first) {
                        cout << i;
                        first--;
                    }else{
                        cout << " " << i;
                    }
                }
            }
        }
        cout << endl;
    }
}
