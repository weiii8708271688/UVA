#include <vector>
#include<iostream>
#include<cmath>
#include <cstring>
#include <algorithm>
using namespace std;

string ans;

void add(string x) {
    string temp = "";
    if(ans.size() > x.size()) {
        for(int i = 0 ; i < ans.size() - x.size() ; i++) {
            temp += '0';
        }
        for(int i = 0 ; i < x.size() ; i++) {
            temp += x[i];
        }
        x = temp;
    }else if(ans.size() < x.size()) {
        for(int i = 0 ; i < x.size() - ans.size() ; i++) {
            temp += '0';
        }
        for(int i = 0 ; i < ans.size() ; i++) {
            temp += ans[i];
        }
        ans = temp;
    }
    temp = "0";
    for(int i = 0 ; i < ans.size() ; i++) {
        int num = ans[i]-'0' + x[i]-'0';
        int tempnum = i;
        if(num >= 10) {
            num -= 10;
            temp[i]++;
        }
        while(temp[tempnum] > '9') {
            temp[tempnum-1]++;
            temp[tempnum]-=10;
            tempnum--;
        }
        temp += num + '0';
    }
    //cout << "temp == " << temp << endl;
    if(temp[0] == '0') {
        temp.erase(0,1);
    }
    ans = temp;
    //cout << "ans ==  " << ans << endl;
}
string twice(string x ,string temp) {
    string s;
    reverse(x.begin(), x.end());
    reverse(temp.begin(), temp.end());
    for(int i = 0 ; i < x.size() ; i++) {
        for(int j = 0 ; j < temp.size() ; j++) {
            s = "";
            int num = (x[i]-'0') * (temp[j] - '0');
            //cout << "x[i] == " << x[i] << " temp[j] == " << temp[j] << "num == " << num << endl;
            if(num > 9) {
                s+=(num/10+'0');
                s+=(num%10+'0');
            }else{
                s+=(num+'0');
            }
            for(int k = 0 ; k < i+j ; k++) {
                s+='0';
            }
            //cout << "s == " << s << endl;
            add(s);
        }
    }
    return ans;
}

int main(){
    string x, temp;
    while(getline(cin, x)) {
        ans = "";
        temp = "";
        int n = x[8] - '0';
        if(isalnum(x[7])) {
            n+=(x[7] -'0')*10;
        }
        int dot = 0;
        if(x[1] == '.') {
            dot = 4;
            x[1] = ' ';
            if(x[0] != '0') {
                temp+=x[0];
            }
            x[0] = ' ';
        }
        if(x[2] == '.') {
            dot = 3;
            x[2] = ' ';
            temp+=x[0];
            temp+=x[1];
            x[0] = ' ';
            x[1] = ' ';
        }
        for(int i = 5 ; i > 0 ; i--) {
            if(x[i] == '0') {
                x[i] = ' ';
                dot--;
            }else{
                break;
            }
        }
        for(int i = 0 ; i < 6 ; i++) {
            if(isalnum(x[i])) {
                temp+=x[i];
                x[i] = ' ';
            }
        }
        dot*=n;
        x = temp;
        //cout << "n == " << n << " x == " << x << endl;
        while(--n) {
            ans = "0";
            x = twice(x, temp);
            //cout << "curx == " << x << endl;
        }
        int Size = x.size();
        if(Size > dot) {
            dot = Size-dot;
            for(int i = 0 ; i < Size ; i++) {
                if(i == dot) cout << '.';
                cout << x[i];
            }
        }else{
            dot = dot-Size;
            cout << '.';
            for(int i = 0 ; i < dot ; i++) {
                cout << '0';
            }
            cout << x;
        }
        cout << endl;
    }
}
