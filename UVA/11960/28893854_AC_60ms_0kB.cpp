#include<iostream>
#include<math.h>
using namespace std ;

int Table[1000001],Ans[1000001];

void Create_Table(){

    Table[1000001]={0};
    int Max = 0,ans;

    for(int i=1;i<=1000000;i++){
        for(int j=i;j<=1000000;j=j+i){
            Table[j] += 1;
        }
    }

    for(int i=1;i<=1000000;i++){

        if(Max <= Table[i]){
            Max = Table[i];
            ans = i;
            Ans[i] = ans;
        }
        else{
            Ans[i] = ans ;
        }
    }

}

int main(){

    int n,m;
    Create_Table();
    cin>>n;
    while(n--){

        cin>>m;
        cout<<Ans[m]<<endl;
    }
}
