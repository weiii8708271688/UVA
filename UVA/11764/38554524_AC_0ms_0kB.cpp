#include <iostream> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T,N; //T筆測資,N表示牆壁的數目
	cin>>T;
	for(int i=0;i<T;++i)
	{
		int H=0,L=0; //H,L代表 high jumps 和 low jumps 的總數 
		cin>>N;
		int high[N]={0}; 
		for(int j=0;j<N;j++)
			cin>>high[j];
		for(int k=N-1;k>0;k--) 
		{
			if(high[k]>high[k-1])
				H++;
			else if(high[k]<high[k-1])
				L++;
		}
			
		cout<<"Case "<<i+1<<": "<<H<<" "<<L<<endl;
	}
}
