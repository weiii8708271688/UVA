#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;
int a, b;
char ch;

int* root = new int [1000000];

int findroot(int x) {
    if(root[x] == x) return x;
    return root[x] = findroot(root[x]);
}

void combine(int a, int b) {
    int roota = findroot(a);
    int rootb = findroot(b);
    if(roota != rootb) {
        root[rootb] = roota;
    }
}


void transfer(string s) {
    ch = s[0];
    int i = 0;
    for(; i < s.size() ; i++) {
        if(isdigit(s[i])) break;
    }
    int temp = 0;
    while(isdigit(s[i])) {
        temp = temp*10 + s[i++]- '0';
    }
    a = temp;
    for(; i < s.size() ; i++) {
        if(isdigit(s[i])) break;
    }
    temp = 0;
    while(isdigit(s[i])) {
        temp = temp*10 + s[i++]- '0';
    }
    b = temp;
}

int main() {
    int case_;
    string s;
    cin >> case_;
    getchar();
    while(case_--) {
        int com;
        int True = 0, False = 0;
        cin >> com;
        for(int i = 0 ; i < com+1 ; i++) {
            root[i] = i;
        }
        getline(cin,s);
        while(getline(cin, s)) {
            if(s == "") break;
            transfer(s);
            if(ch == 'c') {
                combine(a, b);
            }else if(ch == 'q') {
                if(findroot(a) == findroot(b)) {
                    True++;
                }else{
                    False++;
                }
            }
        }
        cout << True << "," << False << endl;
        if(case_) cout << endl;
    }
}
