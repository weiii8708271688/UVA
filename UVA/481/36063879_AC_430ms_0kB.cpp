#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<int> num;
    while(getline(cin, s)) {
        if(s == "") break;
        num.push_back(stoi(s));
    }
    vector <int> tail, prev;
    tail.assign(num.size(), -1);
    prev.assign(num.size(), -1);
    tail[0] = 0;
    int length = 0;
    for(int i = 1 ; i < num.size() ; i++) {
        if(num[i] < num[tail[0]]) {
            tail[0] = i;
        }else if(num[i] > num[tail[length]]){
            prev[i] = tail[length];
            tail[++length] = i;
        }else{
            for(int j = 0 ; j <= length ; j++) {
                if(num[i] <= num[tail[j]]) {
                    tail[j] = i;
                    prev[i] = tail[j-1];
                    break;
                }
            }
        }
        /*cout << "now list: " << endl;
        for(int z = 0 ; z <= length ; z++) {
            cout << tail[z] << endl;
        }
        cout << endl;*/
    }
    cout << length+1 << endl << "-" << endl;
    stack <int> ans;
    for(int i = tail[length] ; i != -1 ; i = prev[i]) {
        ans.push(num[i]);
    }
    while(!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}

