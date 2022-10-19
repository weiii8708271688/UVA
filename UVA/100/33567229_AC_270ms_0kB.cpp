 #include <iostream>
using namespace std;

// returns the maximum cycle-length over all integers
// between and including first and last
int maxCycleLength( int first, int last );

int cycleLength( int n ); // returns the cycle-length of n

int main()
{
	int i, j;
	while( cin >> i >> j )
	{
		cout << i << ' ' << j << ' ';

		if( i > j )
		{
			int buf = i;
			i = j;
			j = buf;
		}

		cout << maxCycleLength( i, j ) << endl;
	}
}

int maxCycleLength( int first, int last )
{
    int max = 0;
	for(int i = first ; i <= last ; i++) {
        int temp = cycleLength(i);
        if(temp > max) {
            max = temp;
        }
	}
	return max;

}

int cycleLength( int n ) //
{
    int ans = 1;
    while( n > 1 )
	{
	    ans++;
		if( n % 2 != 0 )
			n = 3 * n + 1;
		else
			n =  n / 2;
	}
	return ans;

}
