#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

struct index_{
    int index = 0;
    string val;
};

bool cmp(index_ a, index_ b) {
    return a.index < b.index;
}

int main() {
    string s;
    int n;
    cin >> n;
    getline(cin, s);
    getline(cin, s);

    while(n--) {
        index_ a;
        vector <index_> arr;
        getline(cin, s);
        int Size = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            int temp = 0;
            while(isdigit(s[i])) {
                temp = temp*10 + (s[i] - '0');
                i++;
            }
            if(temp) {
                a.index = temp;
                arr.push_back(a);
            }
        }
        for(int i = 0 ; i < arr.size() ; i++) {
            cin >> arr[i].val;
        }
        sort(arr.begin(),arr.end(), cmp);
        for(int i = 0 ; i < arr.size() ; i++) {
            cout<< arr[i].val << endl;
        }
        if(n)cout << endl;
        getline(cin, s);
        getline(cin, s);
    }
}
