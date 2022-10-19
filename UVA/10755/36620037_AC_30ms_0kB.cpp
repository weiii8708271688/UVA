#include <bits/stdc++.h>
using namespace std;

int A, B, C;



long long grid[21][21][21];
long long sum2d[21][21];
long long sum1d[21];

long long get_max1d() {
    long long local_max = sum1d[0];
    long long temp[A] = {0};
    temp[0] = sum1d[0];
    for(int i = 1 ; i < A ; i++) {
        if(temp[i-1] < 0) {
            temp[i] = sum1d[i];
        }else{
            temp[i] = temp[i-1] + sum1d[i];
        }
        local_max = max(local_max, temp[i]);
    }


    return local_max;
}


long long get_max2d() {

    long long Max2d = LLONG_MIN;

    for(int i = 0 ; i < B ; i++) {
        memset(sum1d, 0, sizeof(sum1d));
        for(int t = i ; t < B ; t++) {
            for(int j = 0 ; j < A ; j++) {
                sum1d[j] += sum2d[j][t];
            }
            Max2d = max(Max2d, get_max1d());
        }
    }

    return Max2d;


}


long long get_max3d() {

    long long Max3d = LLONG_MIN;

    for(int i = 0 ; i < C ; i++) {
        memset(sum2d, 0, sizeof(sum2d));
        for(int t = i ; t < C ; t++) {
            for(int j = 0 ; j < A ; j++) {
                for(int k = 0 ; k < B ; k++) {
                    sum2d[j][k] += grid[j][k][t];
                }
            }
            Max3d = max(Max3d, get_max2d());
        }
    }

    return Max3d;

}





int main() {
    int T, t = 1;
    cin >> T;
    while(T--) {
        cin >> A >> B >> C;
        for(int i = 0 ; i < A ; i++) {
            for(int j = 0 ; j < B ; j++){
                for(int z = 0 ; z < C ; z++) {
                    cin >> grid[i][j][z];
                }
            }
        }
        cout << get_max3d() << endl;
        if(T) cout << endl;
    }
}

