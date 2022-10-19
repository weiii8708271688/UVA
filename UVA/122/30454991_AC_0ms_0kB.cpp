#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;

struct node_{
    string order = "";
    int val = 0;
};

node_ transfer(string s) {
    node_ temp;
    int i = 1;
    for(; i < s.size() ; i++) {
        if(s[i] == ',') break;
        temp.val = temp.val*10 + (s[i]-'0');
    }
    i++;
    for(; i < s.size() ; i++) {
        if(s[i] == ')') break;
        temp.order += s[i];
    }
    return temp;
}

bool cmp(node_ a, node_ b) {
    if(a.order.size() != b.order.size()) {
        return a.order.size() < b.order.size();
    }
    int count = 0, i = 0, j = 0;
    while(count == 0) {
        for(; i < a.order.size() ; i++) {
            if(a.order[i] == 'R') break;
            count++;
        }
        for(; j < b.order.size() ; j++) {
            if(b.order[j] == 'R') break;
            count--;
        }
        i++;
        j++;
    }
    return count > 0;
}

int main() {
    string s;
    vector <node_> node;
    while(cin >> s) {
        if(s == "()"){
            bool ans = true;
            for(int i = 0 ; i < node.size()-1 ; i++) {
                for(int j = i+1 ; j < node.size() ; j++) {
                    if(node[i].order == node[j].order) ans = false;
                }
            }
            for(int i = 0 ; i < node.size() ; i++) {
                string s = node[i].order;
                if(s == "") continue;
                s.pop_back();
                bool check = false;
                for(int j = 0 ; j < node.size() ; j++) {
                    if(node[j].order == s) {
                        check = true;
                        break;
                    }
                }
                if(!check) {
                    ans = false;
                    break;
                }
            }
            if(ans) {
                sort(node.begin(), node.end(), cmp);
                for(int i = 0 ; i < node.size()-1 ; i++) {
                    cout << node[i].val << " ";
                }
                cout << node[node.size()-1].val;
            }else{
                cout << "not complete";
            }
            cout << endl;
            node.clear();
            continue;
        }
        node_ temp = transfer(s);
        node.push_back(temp);
    }
}
