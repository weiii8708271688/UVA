

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, a;	
	while (cin >> N)
	{
		// store data
		vector<int> data;
		for (int i = 0; i < N; ++i) cin >> a, data.emplace_back(a);
		// i start with the smallest number
		for (int i = min(data[0], data[N - 1]); i > 0; --i)
		{
			// copy the original data
			vector<int> cpy = data;
			int left = 0, right = N - 1;
			int tmp = i;
			while (right >= 0 && left < N && cpy[left] >= tmp && cpy[right] >= tmp)
			{
				if ((cpy[left] -= tmp) == 0) ++left;
				if ((cpy[right] -= tmp--) == 0) --right;
				
				if (tmp == 0)
				{
					int sum = 0;
					for (auto& j : cpy) sum += j;
					// if i = 1, thete are only two cases: 1 2 and 2 1 1
					if (!(sum & 1) && i != 1 || sum == 0 && i == 1) cout << i << "\n";
					else cout << "no quotation\n";
					goto finish;				
				}
			}
		}
		finish:;
	}
	return 0;
}
