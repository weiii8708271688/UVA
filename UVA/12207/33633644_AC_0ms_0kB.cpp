#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <deque>
using namespace std;


int main() {
    int p, c;
    int cas = 1;
    while(cin >> p >> c) {
        if(!p && !c) break;
        cout << "Case " << cas++ << ":" << endl;
        deque <int> q;
        int table;
        if(p > 1000) table = 1000;
        else table = p;
        for(int i = 1 ; i <= table ; i++) {
            q.push_back(i);
        }
        for(int i = 0 ; i < c ; i++) {

            char ch;
            int temp;
            cin >> ch;
            if(ch == 'N') {
                cout << q.front() << endl;
                q.push_back(q.front());
                q.pop_front();
            }else{
                cin >> temp;
                deque <int> ::iterator it = q.begin();
                for(; it != q.end(); it++) {
                    if((*it) == temp) {
                        q.erase(it);
                        break;
                    }
                }
                q.push_front(temp);
            }
        }
    }
}
