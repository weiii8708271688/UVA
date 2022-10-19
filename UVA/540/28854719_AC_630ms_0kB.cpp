#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;




int main(){
    int sero = 1;
    int n, temp, i, j;
    string s;
    while(cin >> n) {
        if(!n) break;
        vector <int> people[n];
        cout << "Scenario #" << sero++ << endl;
        for(i = 0 ; i < n ; i++) {
            int n2;
            cin >> n2;
            while(n2--) {
                cin >> temp;
                people[i].push_back(temp);
            }
        }
        vector <int> queueline;
        vector <int> queuegroup;
        int checkgroup[n] = {0};
        while(cin >> s) {
            if(s == "STOP") break;
            if(s == "ENQUEUE") {
                cin >> temp;
                int group = -1;
                for(i = 0 ; i < n ; i++) {
                    for(j = 0 ; j < people[i].size() ; j++) {
                        if(people[i][j] == temp) {
                            group = i;
                        }
                        if(group != -1) break;
                    }
                }
                if(checkgroup[group]) {
                    int where = 0;
                    for(i = 0 ; i < queuegroup.size() ; i++) {
                        where += checkgroup[queuegroup[i]];
                        if(queuegroup[i] == group) break;
                    }
                    checkgroup[group]++;
                    queueline.insert(queueline.begin() + where,temp);
                }else{
                    queueline.push_back(temp);
                    checkgroup[group]++;
                    queuegroup.push_back(group);
                }
            }else if(s == "DEQUEUE"){
                if(queueline.empty())continue;
                cout << queueline[0] << endl;
                queueline.erase(queueline.begin());
                checkgroup[queuegroup[0]]--;
                if(checkgroup[queuegroup[0]] == 0) {
                    queuegroup.erase(queuegroup.begin());
                }
            }
        }
        cout << endl;
        queuegroup.clear();
        queueline.clear();
        for(int i = 0 ; i < n ; i++) {
            people[i].clear();
        }
    }
}
