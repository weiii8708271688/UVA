#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

double M_Num, N_Num;
int M_Layer, N_Layer;

void getXY(long long m, long long n) {
    long long i = 0;
    while(true) {
        if( m  <=  i*i ) {
            M_Layer = i;
            M_Num = m - (i-1)*(i-1);
            m = INT_MAX;
        }

        if( n  <=  i*i ) {
            N_Layer = i;
            N_Num = n - (i-1)*(i-1);
            break;
        }
        i++;
    }
}



int slove(int m, int n) {
    int ans = 0;
    while(m != n) {
        getXY(m, n);
        ans++;
        if( ( (M_Layer%2 && m%2) || (M_Layer%2 == 0 && m%2 == 0) ) && M_Layer != N_Layer) {
            m+=(M_Layer*2);
        }else{
            if(M_Num/(M_Layer*2-1) > N_Num/(N_Layer*2-1) ) {
                m--;
            }else{
                m++;
            }
        }
    }
    return ans;
}




int main() {
    int c;
    cin >> c;
    while(c--) {
        long long m, n;
        cin >> m >> n;
        if(m > n) swap(m, n);
        cout << slove(m, n) << endl;
        if(c) cout << endl;
    }
}


