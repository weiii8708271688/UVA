#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;
int project[6][6];

int answer[11][3][5] = {
    0,1,0,0,0, 1,1,1,1,0, 0,0,1,0,0,
    1,0,0,0,0, 1,1,1,1,0, 1,0,0,0,0,
    1,0,0,0,0, 1,1,1,1,0, 0,0,1,0,0,
    1,0,0,0,0, 1,1,1,1,0, 0,1,0,0,0,
    1,0,0,0,0, 1,1,1,1,0, 0,0,0,1,0,
    1,1,0,0,0, 0,1,1,1,0, 0,0,0,1,0,
    1,1,0,0,0, 0,1,1,1,0, 0,0,1,0,0,
    1,1,0,0,0, 0,1,1,1,0, 0,1,0,0,0,
    1,1,1,0,0, 0,0,1,1,1, 0,0,0,0,0,
    0,1,0,0,0, 1,1,1,1,0, 0,1,0,0,0,
    1,1,0,0,0, 0,1,1,0,0, 0,0,1,1,0,
};



bool check(int i, int j) {
    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i+k][j+z] != answer[q][k][z] || i+k > 5 || j+z > 5) {
                    corr = false;
                    break;
                }
            }
        }
        if(corr) return true;
    }

    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i+z][j+k] != answer[q][k][z] || i+z > 5 || j+k > 5) {
                    corr = false;
                    break;
                }
            }
        }
        if(corr) return true;
    }


    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i-k][j-z] != answer[q][k][z] || i-k < 0 || j-z < 0) {
                    corr = false;
                    break;
                }
            }

        }
        if(corr) return true;
    }

    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i-z][j-k] != answer[q][k][z] || i-z < 0 || j-k < 0) {
                    corr = false;
                    break;
                }
            }
        }
        if(corr) return true;
    }

    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i-k][j+z] != answer[q][k][z] || i-k < 0 || j+z > 5) {
                    corr = false;
                    break;
                }
            }
        }
        if(corr) return true;
    }


    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i+k][j-z] != answer[q][k][z] || i+k > 5 || j-z < 0) {
                    corr = false;
                    break;
                }
            }
        }
        if(corr) return true;
    }

    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i-z][j+k] != answer[q][k][z] || i-z < 0 || j+k > 5) {
                    corr = false;
                    break;
                }
            }
        }
        if(corr) return true;
    }

    for(int q = 0 ; q < 11 ; q++) {
        bool corr = true;
        for(int k = 0 ; k < 3 ; k++) {
            if(!corr) break;
            for(int z = 0 ; z < 5 ; z++) {
                if(q != 10 && z == 4) continue;
                if(project[i+z][j-k] != answer[q][k][z] || i+z > 5 || j-k < 0) {
                    corr = false;
                    break;
                }
            }
        }
        if(corr) return true;
    }



    return false;
}




int main() {
    int n;
    cin >> n;
    while(n--) {
        for(int i = 0 ; i < 6 ; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                cin >> project[i][j];
            }
        }
        bool corr = false;
        for(int i = 0 ; i < 6 ; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                if(corr) break;
                corr = check(i, j);
            }
        }
        if(corr) cout << "correct" << endl;
        else cout << "incorrect" << endl;
        if(n) cout << endl;
    }
}


