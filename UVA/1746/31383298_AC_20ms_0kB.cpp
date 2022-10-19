#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    vector <int> num;
    int n;
    while(cin >> n) {
        num.clear();
        for(int i = 0 ; i < n ; i++) {
            int temp;
            cin >> temp;
            num.push_back(temp);
        }
        bool Exit = false;
        for(int i = min(num[0], num[n-1]) ; i > 0 ; i--) {
            if(Exit) break;

            vector <int> cpy = num;
            int L = 0;
            int R = n-1;
            int count = i;

            while(L < n && R >= 0 && cpy[L] >= count && cpy[R] >= count) {
                cpy[R]-=count;
                cpy[L]-=count;
                if(cpy[R] == 0) R--;
                if(cpy[L] == 0) L++;
                count--;
                if(count == 0) {
                    int sum = 0;
                    for(int j = 0 ; j < n ; j++) {
                        sum+=cpy[j];
                    }

                    if(i == 1 && sum == 0) {
                        cout << i << endl;
                    }else if(sum % 2 == 0 && i != 1) {
                        cout << i << endl;
                    }else{
                        cout << "no quotation" << endl;
                    }
                    Exit = true;
                }
            }
        }
    }
}


