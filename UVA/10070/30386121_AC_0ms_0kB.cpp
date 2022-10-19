#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

bool check[3];

bool four(string s) {
    int Size = s.size();
    int temp = (s[Size-1]-'0') + (s[Size-2]-'0')*10;
    if(temp%4) {
        return false;
    }
    return true;
}

bool eleven(string s) {
    int sum = 0;
    for(int i = 0 ; i < s.size() ; i++) {
        if(i%2) {
            sum += (s[i]-'0');
        }else{
            sum -= (s[i]-'0');
        }
    }
    if(sum%11) {
        return false;
    }
    return true;
}

bool five(string s){
    int Size = s.size();
    if( (s[Size-1] - '0') % 5) {
        return false;
    }
    return true;
}

bool three(string s) {
    int sum = 0;
    for(int i = 0 ; i < s.size() ; i++) {
        sum += (s[i] - '0');
    }
    if(sum%3) {
        return false;
    }
    return true;
}

bool hundred(string s) {
    int Size = s.size();
    if(s[Size-1] != '0') return false;
    if(s[Size-2] != '0') return false;
    return true;
}

int main() {
    string s;
    int first = 0;
    while(getline(cin, s)) {
        if(first++) cout << endl;
        for(int i = 0 ; i < 3 ; i++) {
            check[i] = false;
        }
        if(four(s)) {
            if(hundred(s)) {
                int Size = s.size();
                string temp = "";
                temp+=s[Size-4];
                temp+=s[Size-3];
                if(four(temp)) check[0] = true;
            }else{
                check[0] = true;
            }
        }
        if(three(s) && five(s)) check[1] = true;
        if(eleven(s) && five(s) && check[0]) check[2] = true;
        if(check[0]) {
            cout << "This is leap year." << endl;
        }
        if(check[1]) {
            cout << "This is huluculu festival year." << endl;
        }
        if(check[2]) {
            cout << "This is bulukulu festival year." << endl;
        }
        if(!check[0] && !check[1]) {
            cout << "This is an ordinary year." << endl;
        }
    }
}
