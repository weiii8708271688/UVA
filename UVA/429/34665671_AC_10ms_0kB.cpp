#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;

vector <vector<int>> G;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--) {
        string s;
        vector <string> word;
        while(getline(cin,s)) {
            if(s == "*") break;
            word.push_back(s);
        }

        int ans[word.size()][word.size()];


        for(int i = 0 ; i < word.size() ; i++) {
            for(int j = 0 ; j < word.size() ; j++) {
                int err = 0;
                if(word[i].size() == word[j].size()) {
                    for(int z = 0 ; z < word[i].size() ; z++) {
                        if(word[i][z] != word[j][z]) err++;
                    }
                }
                if(err == 1) {
                    ans[i][j] = 1;
                }else if(i == j) {
                    ans[i][j] = 0;
                }else{
                    ans[i][j] = 1000000;
                }
            }
        }


        for(int k = 0 ; k < word.size() ; k++) {
            for(int i = 0 ; i < word.size() ; i++) {
                for(int j = 0 ; j < word.size() ; j++) {
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                }
            }
        }





        while(getline(cin,s)) {
            if(s == "") break;
            string st = "", en = "";
            bool f = true;
            for(int i = 0 ; i < s.size() ; i++) {
                if(s[i] == ' ') {
                    f = false;
                    continue;
                }
                if(f) {
                    st += s[i];
                }else{
                    en += s[i];
                }
            }
            int s_index, e_index;

            for(int i = 0 ; i < word.size() ; i++) {
                if(word[i] == st) s_index = i;
                if(word[i] == en) e_index = i;
            }
            cout << st << " " << en << " " << ans[s_index][e_index] << endl;

        }
        if(n) cout << endl;
    }
}
