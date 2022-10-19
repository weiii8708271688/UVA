#include <iostream> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T,N,max; //T組數據 ,一組 N個數字 
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N; //幾組數據 
		int array[N]={0};
		for(int j=0;j<N;j++) //輸入數據到陣列 
			cin>>array[j];
		max=array[0];
		for(int k=0;k<N;k++) //比大小啦 
		{
			if(array[k]>max)
				max=array[k];
		}
	cout<<"Case "<<i+1<<": "<<max<<endl;

	}

} 