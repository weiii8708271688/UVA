#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

struct car_{
    string way;
    int arrive;
    int ans;
    bool hasans = false;
};

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n, t, m;
        string s;
        queue <int> right, left;
        cin >> n >> t >> m;
        car_ car[m];
        int time = 0, side = 0; //0 = left, 1 = right
        for(int i = 0 ; i < m ; i++) {
            int temp;
            cin >> temp >> s;
            car[i].way = s;
            car[i].arrive = temp;
            if(s == "right") right.push(temp);
            else left.push(temp);
        }
        int onship = 0;
        stack <int> time_s;
        while(true) {
            for(int i = 0 ; i < onship ; i++) {
                for(int j = 0 ; j < m ; j++) {
                    if(car[j].hasans) continue;
                    if(car[j].arrive == time_s.top()) {
                        if(car[j].way == "right" && side == 0) {
                            car[j].ans = time;
                            car[j].hasans = true;
                            break;
                        }else if(car[j].way == "left" && side == 1) {
                            car[j].ans = time;
                            car[j].hasans = true;
                            break;
                        }
                    }
                }
                time_s.pop();
            }
            if(right.empty() && left.empty()) break;
            onship = 0;
            if(side == 0) {
                side = 1;
                if(left.empty()) {
                    if(time < right.front()) {
                        time = right.front() + t;
                    }else{
                        time += t;
                    }
                    continue;
                }
                if(left.front() > time) {
                    if(right.empty() || right.front() > left.front()) {
                        time = left.front();
                        time_s.push(left.front());
                        left.pop();
                        onship++;
                        if(left.empty()) {
                            time += t;
                            continue;
                        }
                        while(left.front() <= time && onship < n) {
                            onship++;
                            time_s.push(left.front());
                            left.pop();
                            if(left.empty()) break;
                        }
                        time += t;
                        continue;
                    }else{
                        if(time < right.front()) {
                        time = right.front() + t;
                        }else{
                            time += t;
                        }
                        continue;
                    }

                }else{
                    while(left.front() <= time && onship < n) {
                        onship++;
                        time_s.push(left.front());
                        left.pop();
                        if(left.empty()) break;
                    }
                    time += t;
                    continue;
                }
            }else{
                side = 0;
                if(right.empty()) {
                    if(time < left.front()) {
                        time = left.front() + t;
                    }else{
                        time += t;
                    }
                    continue;
                }
                if(right.front() > time) {
                    if(left.empty() || left.front() > right.front()) {
                        time = right.front();
                        time_s.push(right.front());
                        right.pop();
                        onship++;
                        if(right.empty()) {
                            time += t;
                            continue;
                        }
                        while(right.front() <= time && onship < n) {
                            onship++;
                            time_s.push(right.front());
                            right.pop();
                            if(right.empty()) break;
                        }
                        time += t;
                        continue;
                    }else{
                        if(time < left.front()) {
                        time = left.front() + t;
                        }else{
                            time += t;
                        }
                        continue;
                    }

                }else{
                    while(right.front() <= time && onship < n) {
                        onship++;
                        time_s.push(right.front());
                        right.pop();
                        if(right.empty()) break;
                    }
                    time += t;
                    continue;
                }
            }
        }
        for(int i = 0 ; i < m ; i++) {
            cout << car[i].ans << endl;
        }
        if(c)
            cout << endl;
    }
}
