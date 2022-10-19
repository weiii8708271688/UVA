#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;


int main() {
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    while(n--) {
        int Ram[1000] = {0}, R[10] = {0};
        int c = 0;
        while(getline(cin, s)) {
            if(s == "") break;
            Ram[c++] = stoi(s);
        }
        int ans = 1, pointer = 0;
        while(Ram[pointer] != 100) {
            int one = Ram[pointer]/100;
            int two = Ram[pointer]/10%10;
            int three = Ram[pointer]%10;
            pointer++;
            switch(one) {
                case 2:
                    R[two] = three; break;
                case 3:
                    R[two] += three; break;
                case 4:
                    R[two] *= three; break;
                case 5:
                    R[two] = R[three]; break;
                case 6:
                    R[two] += R[three]; break;
                case 7:
                    R[two] *= R[three]; break;
                case 8:
                    R[two] = Ram[R[three]];break;
                case 9:
                    Ram[R[three]] = R[two];break;
                case 0:
                    if(R[three] != 0) {
                        pointer = R[two];
                    }
            }

            R[two]%=1000;
            ans++;
        }
        cout << ans << endl;
        if(n) cout << endl;
    }
}
