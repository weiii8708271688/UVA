#include<iostream>
#include<cstring>
using namespace std;
char s1[30],s2[30]; //先序和中序
void build(int p1,int p2,int q1){
	if(p1>p2)return ;
	int i=q1;                                //0123456   0123456
	while(s1[p1]!=s2[i])i++;                 //DBACEGF   ABCDEFG
	build(p1+1,p1+i-q1,q1);//左

	build(p1+1+i-q1,p2,i+1);//右
    //cout << "p1 == " << p1 << " p2 == " << p2 << " q1 == " << q1 << " i == " << i << endl;
	cout<<s2[i];

}


int main(){
	while(cin>>s1>>s2){
		int len = strlen(s1)-1;
		build(0,len,0);
		puts("");
	}

	return 0;
}
