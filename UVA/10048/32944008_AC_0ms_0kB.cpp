/*
Floyd演算法min(map[i][j],max(map[i][k],map[k][j]))
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;
int map[MAX][MAX];
int n,k;

//not me

int main(){
  int c,s,q,ncase=1,a,b,w;
  while (scanf("%d%d%d",&c,&s,&q)){
  	if (c==0 && s==0 && q==0) break;
  	for(int i=1;i<=c;i++){
  		for(int j=1;j<=c;j++){
  			map[i][j]=99999999;
			}
		}
    for(int i=0;i<s;i++){
    	scanf("%d%d%d",&a,&b,&w);
      map[a][b]=w;
			map[b][a]=w;        
    }
    for(int k=1;k<=c;k++){  //Floyd
      for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
          if ((map[i][k] != 99999999)&&(map[k][j]!=99999999)) {
            map[i][j]=min(map[i][j],max(map[i][k],map[k][j]));                                      
          }            
        }              
      }                    
    }
    if (ncase > 1) printf("\n");
    printf("Case #%d\n",ncase++);
    for(int i=0;i<q;i++){
    	scanf("%d%d",&a,&b);
			if (map[a][b]==99999999) printf("no path\n");
			else printf("%d\n",map[a][b]);	
		}   
  }         
}