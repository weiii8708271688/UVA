#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

int step;
vector <int> A,B,C;
string s[300];
string real;
int a;
void output() {
    cout << "A=>";
    if(!A.empty()) {
        cout << " " << " ";
        for(int i = 0 ; i < A.size() ; i++) {
            cout << " " << A[i];
        }
    }
    cout << endl;
    cout << "B=>";
    if(a % 2) {
        if(!C.empty()) {
            cout << " " << " ";
            for(int i = 0 ; i < C.size() ; i++) {
                cout << " " << C[i];
            }
        }
        cout << endl;
        cout << "C=>";
        if(!B.empty()) {
            cout << " " << " ";
            for(int i = 0 ; i < B.size() ; i++) {
                cout << " " << B[i];
            }
        }
    }else{
        if(!B.empty()) {
            cout << " " << " ";
            for(int i = 0 ; i < B.size() ; i++) {
                cout << " " << B[i];
            }
        }
        cout << endl;
        cout << "C=>";
        if(!C.empty()) {
            cout << " " << " ";
            for(int i = 0 ; i < C.size() ; i++) {
                cout << " " << C[i];
            }
        }
    }
    cout << endl;
    cout << endl;
}


void pp(char a, char b,int n) {
    if(!step) return;
    if(n>1) {
        s[n]+=a;
        s[n]+=b;
    }
    if(!step) return;
    switch(a) {
        case 'A':
            switch(b) {
                case 'B':
                    B.push_back(A.back());
                    A.pop_back();
                    break;
                case 'C' :
                    C.push_back(A.back());
                    A.pop_back();
                    break;
            }
        break;
        case 'B':
            switch(b) {
                case 'A':
                    A.push_back(B.back());
                    B.pop_back();
                    break;
                case 'C' :
                    C.push_back(B.back());
                    B.pop_back();
                    break;
            }
        break;
        case 'C':
            switch(b) {
                case 'A':
                    A.push_back(C.back());
                    C.pop_back();
                    break;
                case 'B' :
                    B.push_back(C.back());
                    C.pop_back();
                    break;
            }
        break;
    }
    step--;
    output();
}
void fun(int n){
    if(!step) return;
    if(n%2) {
        pp('A','B',n);
        real = "CAB";
    }else {
        pp('A','C',n);
        real = "BCA";
    }
    if(!step) return;
    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ; j < s[i].size() ; j+=2) {
            if(!step) return;
            switch(s[i][j]) {
                case 'A' :
                    switch(s[i][j+1]) {
                        case 'B' :
                            pp(real[0],real[1],n);
                            break;
                        case 'C' :
                            pp(real[0],real[2],n);
                            break;
                    }
                break;
                case 'B' :
                    switch(s[i][j+1]) {
                        case 'A' :
                            pp(real[1],real[0],n);
                            break;
                        case 'C' :
                            pp(real[1],real[2],n);
                            break;
                    }
                break;
                case 'C' :
                    switch(s[i][j+1]) {
                        case 'B' :
                            pp(real[2],real[1],n);
                            break;
                        case 'A' :
                            pp(real[2],real[0],n);
                            break;
                    }
                break;
            }
        }
    }
}





int main() {
    int ca = 1;
    while(cin >> a >> step) {
        if(!a && !step) break;
        cout << "Problem #" << ca++ << endl << endl;
        A.clear();
        B.clear();
        C.clear();
        for(int i = a ; i > 0 ; i--) {
            A.push_back(i);
            s[i].clear();
        }
        real = "ABC";
        s[1] = "AB";
        output();
        int time = 1;
        while(step) {
            fun(time++);
        }
    }
}
