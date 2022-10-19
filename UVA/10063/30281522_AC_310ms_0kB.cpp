#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;


string s;


void output(int Size, string temp) {
    for(int i = 0 ; i <= Size ; i++) {
        temp.insert(temp.begin() + i, s[Size]);
        if(Size == s.size()-1) cout << temp << endl;
        else output(Size+1, temp);
        temp.erase(temp.begin() + i);
    }
}


int main() {
    int n = 0;
    while(cin >> s) {
        if(n++) cout << endl;
        string temp = "";
        output(0, temp);
    }
}
