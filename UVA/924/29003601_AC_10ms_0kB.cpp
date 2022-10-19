#include <vector>
#include<iostream>
#include<cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector <int> fri[n];
    for(int i = 0 ; i < n ; i++) {
        int temp, temp2;
        cin >> temp;
        for(int j = 0 ; j < temp ; j++) {
            cin >> temp2;
            fri[i].push_back(temp2);
        }
    }
    int casenum;
    cin >> casenum;
    while(casenum--) {
        int first;
        int M = 1;
        int day = 1;
        bool whoknow[n] = {0};
        vector <int> today;
        cin >> first;
        if(fri[first].empty()) {
        cout << 0 << endl;
        continue;
        }
        int D = 1;
        whoknow[first] = true;
        while(true) {
            today.clear();
            bool allknow = true;
            int temp = 0;
            for(int i = 0 ; i < n ; i++) {
                if(!whoknow[i]) {
                    allknow = false;
                }else{
                    today.push_back(i);
                }
            }
            if(allknow) break;
            for(int i = 0 ; i < today.size() ; i++) {
                int todo = today[i];
                for(int j = 0 ; j < fri[todo].size() ; j++) {
                    int people = fri[todo][j];
                    if(!whoknow[people]) {
                        whoknow[people] = true;
                        temp++;
                    }
                }
            }
            //cout << "Day " << day << " temp == " << temp << endl;
            if(temp > M) {
                M = temp;
                D = day;
            }
            if(temp == 0) break;
            day++;
        }
        cout << M << " " << D << endl;
    }
}
