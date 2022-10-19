#include <iostream> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int k,n,m ; //k作為判斷是否繼續進行的依據 
	while(cin>>k)
	{
		if (k==0) //如果k=0則跳出迴圈 
	       break;
		cin>>n>>m ; //輸入參考點(n,m) 
		int x,y;
		for(int i=0;i<k;i++) {
			cin>>x>>y ;
		if(x-n>0 && y-m<0)
			cout<<"SE\n";	
		else if(x-n>0 && y-m>0)
			cout<<"NE\n";
		else if(x-n<0 && y-m>0)
			cout<<"NO\n";
		else if(x-n<0 && y-m<0)
			cout<<"SO\n";
		else if(n==x || m==y)
		    cout<<"divisa\n";
	    }
		
	}	
	return 0;
}