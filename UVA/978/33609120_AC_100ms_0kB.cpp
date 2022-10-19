#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;


int main() {
    int c;
    cin >> c;
    while(c--) {
        int B, SG, SB, temp;
        cin >> B >> SG >> SB;
        multiset <int> sg, sb;
        for(int i = 0 ; i < SG ; i++) {
            cin >> temp;
            sg.insert(temp);
        }
        for(int i = 0 ; i < SB ; i++) {
            cin >> temp;
            sb.insert(temp);
        }
        int battle[B];
        while(!sg.empty() && !sb.empty()) {
            int count = 0;
            for(int i = 0 ; i < B ; i++) {
                if(sg.empty() || sb.empty()) {
                    break;
                }
                int g = *sg.rbegin();
                int b = *sb.rbegin();
                battle[count++] = g-b;
                sg.erase(--sg.end());
                sb.erase(--sb.end());
            }
            for(int i = 0 ; i < count ; i++) {
                if(battle[i] > 0) {
                    sg.insert(battle[i]);
                }else if(battle[i] < 0){
                    sb.insert(-battle[i]);
                }
            }
        }

        if(sg.empty() && sb.empty()) {
            cout << "green and blue died" << endl;
        }else if(sg.empty()) {
            cout << "blue wins" << endl;
            while(!sb.empty()) {
                int b = *sb.rbegin();
                cout << b << endl;
                sb.erase(--sb.end());
            }
        }else{
            cout << "green wins" << endl;
            while(!sg.empty()) {
                int g = *sg.rbegin();
                cout << g << endl;
                sg.erase(--sg.end());
            }
        }
        if(c) cout << endl;



    }
}
