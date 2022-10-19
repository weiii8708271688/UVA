#include <vector>
#include<iostream>
#include<cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;



int min(int a, int b) {
    if(a > b) return b;
    return a;
}


int main(){
    int node1,node2;
    int count = 1;
    while(cin >> node1 >> node2) {
        if(!node1 && !node2) break;
        vector <int> allnode;
        allnode.push_back(node1);
        allnode.push_back(node2);
        int path[101][101];
        for(int i = 0 ; i < 101 ; i++) {
            for(int j = 0 ; j < 101 ; j++) {
                path[i][j] = 1000;
            }
        }
        path[node1][node2] = 1;
        while(cin >> node1 >> node2) {
            if(!node1 && !node2) break;
            bool caninin = true, caninin2 = true;
            for(int i = 0 ; i < allnode.size() ; i++) {
                if(allnode[i] == node1) {
                    caninin = false;
                }
                if(allnode[i] == node2) {
                    caninin2 = false;
                }
            }
            if(caninin) allnode.push_back(node1);
            if(caninin2) allnode.push_back(node2);
            path[node1][node2] = 1;
        }
        int Size = allnode.size();
        for(int k = 0 ; k < Size ; k++) {
            for(int i = 0 ; i < Size ; i++) {
                for(int j = 0 ; j < Size ; j++) {
                    path[allnode[i]][allnode[j]] = min(path[allnode[i]][allnode[j]], path[allnode[i]][allnode[k]] + path[allnode[k]][allnode[j]]);
                }
            }
        }
        double sum = 0;
        for(int i = 0 ; i < Size ; i++) {
            for(int j = 0 ; j < Size ; j++) {
                if(i!=j) sum+=path[allnode[i]][allnode[j]];
            }
        }
        cout << "Case "<< count++ << ": average length between pages = ";
        cout << fixed << setprecision(3) << sum/(Size * (Size-1)) << " clicks" <<  endl;
        allnode.clear();
    }
}
