/*
使用L與R紀錄子字串的左右邊界，使用set記憶目前in[L]到in[R]的數字， 
當新加入L[R]與set中元素重複，就記錄目前的L-R的值是否比較大，
依序從set中刪除in[L]往後的元素刪除直到L[R]不重複，繼續讀取L[R]以後的字元 
*/
#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int in[1000001];



//not me

int main(){
	set<int> s;
	int ca,n,a,maxlen,L,R;
	cin >> ca;
	for(int i=0;i<ca;i++){
		cin >> n;
		s.clear();
		for(int i=0;i<n;i++){
			cin >> in[i];//輸入所有元素到in[] 
		}
		L=maxlen=0;
		R=0;
		while(R<n){
			if (s.count(in[R])==0)	{//判斷in[R]是否重複 
				s.insert(in[R]);//若沒有重複插入s 
				R++;
				maxlen=max(maxlen,R-L);//紀錄目前的長度 
			}else{//s中in[R]重複 
				while(s.count(in[R])>0){//若還是重複 
					s.erase(in[L]);//不斷刪除s中的in[L] 
					L++;
				}
			}		
		}
		cout << maxlen<<endl;
	}	
} 