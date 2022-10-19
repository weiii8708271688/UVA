#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>



using namespace std;


int main() {
    int c;
    cin >> c;
    cin.ignore();
    cin.ignore();
    while(c--) {
        string s;
        map <string, int> name;
        int all = 0;
        while(getline(cin, s)) {
            if(s == "") break;
            name[s]++;
            all++;
        }
        map <string, int> ::iterator it = name.begin();
        for(; it != name.end() ; it++) {
            cout << it->first << " " << fixed << setprecision(4) << (double)it->second/all*100 << endl;
        }
        if(c) cout << endl;
    }
}
