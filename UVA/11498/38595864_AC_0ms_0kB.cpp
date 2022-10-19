#include <iostream>
using namespace std;
int main()
{
	int K, N, M, X, Y;
	while (cin >> K)
	{
	    cin >> N >> M;
		while (K--)
		{
			cin >> X >> Y;
			if (X - N > 0 && Y - M > 0) cout << "NE" << endl;
			else if (X - N < 0 && Y - M > 0) cout << "NO" << endl;
			else if (X - N > 0 && Y - M < 0) cout << "SE" << endl;
			else if (X - N < 0 && Y - M < 0) cout << "SO" << endl;
			else cout << "divisa" << endl;
		}
	}
	return 0;
}