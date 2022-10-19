#include <iostream> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,f ; //n組數據,f位農夫 
	long long m,a,b,c; //a,b,c 代表面積,動物數量,環保等級  
	cin>>n; 
	for(int i=0;i<n;i++){
	  cin>>f ;
	  for(int j=0;j<f;j++){
	    cin>>a>>b>>c;
		m=m+(a*c); //m代表每組農夫獲得金額 
      }
      cout<<m<<endl;
      m=0 ;
    }
    
}
