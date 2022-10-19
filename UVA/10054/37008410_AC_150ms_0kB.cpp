//not me

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100;
int G[maxn][maxn], degree[maxn];


void euler(int u){
    for(int v = 1; v <= 50; v++){
        if(G[u][v]){
            G[u][v]--, G[v][u]--;
            euler(v);
            printf("%d %d\n", v, u);   //逆序輸出
        }
    }
}

void init(){
    memset(G, 0, sizeof(G));
    memset(degree, 0, sizeof(degree));
}

int main(){
    int T, n;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++){
        if(kase > 1) printf("\n");
        scanf("%d", &n);
        init();
        int u, v;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &u, &v);
            degree[u]++, degree[v]++;
            G[u][v]++, G[v][u]++;
        }
        int ans = 0;
        for(int i = 0; i < maxn; i++)
            if(degree[i]%2){ ans = 1; break;}
        if(ans) printf("Case #%d\nsome beads may be lost\n", kase);
        else{
            printf("Case #%d\n", kase);
            euler(u);
        }
    }
    return 0;
}