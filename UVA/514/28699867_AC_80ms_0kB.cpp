#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;




int main(){
    int n;
    int count = 1;
    while(cin >> n) {
        int out[n+1];
        if(!n) break;
        bool wronginput = false;
        while(true) {
            vector<int> station;
            count = 1;
            for(int i = 1 ; i <= n ; i++) {
                cin >> out[i];
                if(out[i] == 0) {
                    wronginput = true;
                    break;
                }
            }
            if(wronginput) break;
            for(int i = 1 ; i <= n ; i++) {
                station.push_back(i);
                while(out[count]==station.back()) {
                    count++;
                    station.pop_back();
                }
            }
            if(station.empty()) {
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
}

