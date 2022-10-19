#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>



using namespace std;


int main() {
    string s;
    map<string, string> name;
    while(getline(cin, s)) {
        if(s == "") break;
        string a = "" , b = "";
        bool atime = true;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == ' ') {atime = false; i++;}
            if(atime) {
                a += s[i];
            }else{
                b += s[i];
            }
        }
        name[b] = a;
    }



    while(cin >> s) {
        map<string, string>:: iterator it;
        it = name.find(s);
        if(it != name.end()) {
            cout << it->second << endl;
        }else {
            cout << "eh" << endl;
        }
    }
}
