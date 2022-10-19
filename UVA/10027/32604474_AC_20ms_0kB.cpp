#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;
vector <pair<string, string>> translate;
vector <string> ans;





bool used(string s) {
    if(ans.size() > 1000) return false;
    for(int i = 0 ; i < ans.size() ; i++) {
        if(ans[i] == s) {
            return false;
        }
    }
    return true;
}

void makepair(string s) {
    string L = "", R = "";
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] == '-' && s[i+1] == '>') {
            i+=2;
            for(; i < s.size() ; i++) {
                if(s[i] != '"')
                    R+=s[i];
            }
        }else{
            if(s[i] != '"')
                L+=s[i];
        }
    }
    if(L != R) {
        pair<string, string> temp;
        temp = make_pair(L, R);
        translate.push_back(temp);
    }
}

void find_new_word(string s) {
    if(ans.size() > 1000) return;
    for(int i = 1 ; i <= s.size()-2 ; i++) {
        if(ans.size() > 1000) return;
        for(int j = 1 ; j <= s.size()-i-1 ; j++) {
            if(ans.size() > 1000) return;
            for(int z = 0 ; z < translate.size() ; z++) {
                if(ans.size() > 1000) return;
                bool pass = false;
                if(translate[z].first.size() == i) {
                    pass = true;
                    for(int k = 0 ; k < i ; k++) {
                        if(s[j+k] != translate[z].first[k]) {
                            pass = false;
                        }
                    }
                }
                if(ans.size() > 1000) return;
                if(pass) {
                    string temp = "\"";
                    for(int k = 1 ; k < j ; k++) {
                        temp += s[k];
                    }
                    temp += translate[z].second;
                    for(int k = j+i ; k < s.size()-1 ; k++) {
                        temp += s[k];
                    }
                    temp += '"';
                    if(ans.size() > 1000) return;
                    if(used(temp)) {
                        ans.push_back(temp);
                        find_new_word(temp);
                    }
                }
            }
        }
    }
}


int main() {
    string s, temp;
    int n;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    while(n--) {
        getline(cin, s);
        ans.clear();
        translate.clear();
        while(getline(cin, temp)) {
            if(temp == "") break;
            makepair(temp);
        }
        ans.push_back(s);
        bool spc = false;
        for(int i = 0 ; i < translate.size() ; i++){
            if(translate[i].first.empty()) {
                spc = true;
            }
        }
        find_new_word(s);
        if(ans.size() > 1000 || spc) {
            cout << "Too many." << endl;
        }else{
            cout << ans.size() << endl;
        }
        if(n) cout << endl;
    }
}


