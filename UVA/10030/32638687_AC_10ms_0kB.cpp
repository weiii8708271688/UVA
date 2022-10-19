#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

map<string, int> count_n, count_e;
vector <string> ori;

int main() {
    int test;
    cin >> test;
    while(test--) {
        count_n.clear(); count_e.clear(); ori.clear();
        int n,m;
        cin >> n >> m;
        string temp;
        string name[n], ext[n];
        for(int i = 0 ; i < n ; i++) {
            name[i] = "";
            ext[i] = "";
            cin >> temp;
            ori.push_back(temp);
            int j;
            for(j = 0 ; j < temp.size() ; j++) {
                if(temp[j] == '.') {
                    break;
                }
            }
            for(int k = 0 ; k < j ; k++) {
                    name[i] += temp[k];
            }
            if(j == temp.size() || j == temp.size()-1) {
                ext[i] = "";
            }else{
                for(int k = j+1 ; k < temp.size() ; k++) {
                    ext[i] += temp[k];
                }
            }

            count_n[name[i]]++;
            count_e[ext[i]]++;
        }

        int count = n;
        bool output[n] = {0};
        for(int i = 0 ; i < m ; i++) {
            if(i % 2 == 0) {
                for(auto &it: count_e) {
                    if(it.second == 1) {
                        it.second--;
                        for(int j = 0 ; j < n ; j++){
                            if(ext[j] == it.first && !output[j]) {
                                count_n[name[j]]--;
                                output[j] = true;
                                count--;
                                break;
                            }
                        }
                    }
                }
            }else{
                for(auto &it: count_n) {
                    if(it.second == 1) {
                        it.second--;
                        for(int j = 0 ; j < n ; j++){
                            if(name[j] == it.first && !output[j]) {
                                count_e[ext[j]]--;

                                output[j] = true;
                                count--;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << count << endl;
        for(int i = 0 ; i < n ; i++) {
            if(!output[i]) {
                cout << ori[i] << endl;
            }
        }
        if(test) cout << endl;
    }
}


