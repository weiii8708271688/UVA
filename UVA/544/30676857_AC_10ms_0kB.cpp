#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;
int ton[201][201];
vector <string> city;
int serach(string s, int num) {
    int i;
    for(i = 0 ; i < city.size() ; i++) {
        if(city[i] == s) {
            return i;
        }
    }
    if(city.size() != num) {
        city.push_back(s);
    }
    return i;
}



int main() {
    int scen = 1, num, road, load;
    while(cin >> num >> road) {
        if(!num && !road) break;
        cout << "Scenario #" << scen++ << endl;
        city.clear();
        for(int i = 0 ; i < num ; i++) {
            for(int j = 0 ; j < num ; j++) {
                ton[i][j] = 0;
            }
        }
        int num1, num2;
        string s1, s2;
        for(int i =  0 ; i < road ; i++) {
            cin >> s1 >> s2 >> load;
            num1 = serach(s1,num);
            num2 = serach(s2,num);
            if(load > ton[num1][num2]) ton[num1][num2] = load;
            if(load > ton[num2][num1]) ton[num2][num1] = load;
        }
        for(int k = 0 ; k < num ; k++) {
            for(int i = 0 ; i < num ; i++) {
                for(int j = 0 ; j < num ; j++) {
                    if(ton[i][k] && ton[k][j]) {
                        ton[i][j] = max(ton[i][j], min(ton[i][k], ton[k][j]));
                    }
                }
            }
        }
        cin >> s1 >> s2;
        num1 = serach(s1,num);
        num2 = serach(s2,num);
        cout << ton[num1][num2] << " tons" << endl << endl;
    }
}
