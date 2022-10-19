#include <iostream>
using namespace std;
int main(){
	int n,dep,ball,ans;
	cin >> n;
	for(int j=0;j<n;j++){
		cin >> dep >>ball;
		ans=1;
		for(int i=1;i<dep;i++){
			if ((ball%2)==1){
				ans=2*ans;  //往左走，二元完全數編號有規則性 
				ball=(ball+1)/2;  //到下一個點當成root，調整新的ball值 
			}else{
				ans=2*ans+1;  //往右走，二元完全數編號有規則性 
				ball=ball/2;   //到下一個點當成root，調整新的ball值  
			}
		}
		cout << ans<<endl;
	}
	cin >> n;
}