#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

string ans[301], ans1[301];

string bigplus(string a, string b) {
    int aSize = a.size();
    int bSize = b.size();
    if(aSize > bSize) {
        for(int i = 0; i < aSize - bSize; i++) {
            b.insert(b.begin(), '0');
        }
        bSize = aSize;
    }else {
        for(int i = 0 ; i < bSize - aSize ; i++) {
            a.insert(a.begin(), '0');
        }
        aSize = bSize;
    }
    for(int i = 0 ; i < aSize ; i++) {
        a[i] = a[i] + b[i] - '0';
    }
    for(int i = aSize - 1 ; i > 0 ; i--) {
        if(a[i] > '9') {
            a[i] -= 10;
            a[i-1]++;
        }
    }
    if(a[0] > '9') {
        a.insert(a.begin(), '1');
        a[1] -= 10;
    }
    return a;
}

string bigmin(string a, string b) {
    vector<int> temp;
    for(int i = 0 ; i < a.size() + b.size() ; i++) {
        temp.push_back(0);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0 ; i < a.size() ; i++) {
        for(int j = 0 ; j < b.size() ; j++) {
            int A = a[i] - '0';
            int B = b[j] - '0';
            temp[i+j] += (A*B);
        }
    }
    for(int i = 0 ; i <  temp.size() ; i++) {
        while(temp[i] > 9) {
            temp[i] -= 10;
            temp[i+1]++;
        }
    }
    reverse(temp.begin(), temp.end());
    if(temp[0] == 0) {
        temp.erase(temp.begin());
    }
    string temp1;
    for(int i = 0 ; i < temp.size() ; i++) {
        char ch = temp[i] + '0';
        temp1.insert(temp1.end() ,ch);
    }
    return temp1;
}






void fun(int i) {
    ans[i] = bigplus(ans[i], ans[i-1]);
    ans[i] = bigplus(ans[i], ans[i-1]);
    for(int j = 1 ; j < i ; j++) {
        string temp = bigmin(ans[i-j-1],ans[j-1]);
        ans[i] = bigplus(ans[i], temp);
    }
}






int main() {
    int n;
    for(int i = 0 ; i < 301 ; i++) {
        ans[i] = "0";
    }
    ans1[1] = "1";
    ans[0] = "1";
    ans[1] = "2";
    for(int i = 2 ; i < 301 ; i++) {
        fun(i);
        string s = "";
        int temp = i;
        while(temp != 0) {
            char ch = temp%10 + '0';
            s.insert(s.begin(), ch);
            temp/=10;
        }
        ans1[i] = bigmin(ans1[i-1], s);
    }
    while(cin >> n) {
        if(!n) break;
        cout << bigmin(ans[n-1], ans1[n]) << endl;
    }
}


