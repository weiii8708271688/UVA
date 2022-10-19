#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
#include <map>
using namespace std;

string s;

bool cmp(string a, string b) {
    return a.size() < b.size();
}

vector <string> store;

bool exist(int j) {
    for(int i = 0 ; i < store.size() ; i++) {
        if(store[i] == store[j] && i != j) {
            return true;
        }
    }
    return false;
}


int main() {
    int n;
    cin >> n;
    cin.ignore();
    while(n--) {
        getline(cin,s);
        store.clear();
        string temp = "";
        temp += s[0];
        store.push_back(temp);
        for(int i = 1 ; i < s.size() ; i++) {
            int Size = store.size();

            for(int j = 0 ; j < Size ; j++) {
                temp = store[j];
                if(temp[0] == s[i]) {
                    temp.erase(temp.begin());
                    store.push_back(temp);
                }
                store[j] += s[i];
                if(store[j].size() > 10 || exist(j)) {
                    store.erase(store.begin()+j);
                    j--;
                    Size--;
                }
            }
        }
        if(store.empty()) {
            cout << "Not consistent with the theory" << endl;
        }else{
            sort(store.begin(), store.end(), cmp);
            if(store[0] == "") {
                cout << "An echo string with buffer size ten" << endl;
            }else{
                cout << "Not an echo string, but still consistent with the theory" << endl;
            }
        }
    }
}
