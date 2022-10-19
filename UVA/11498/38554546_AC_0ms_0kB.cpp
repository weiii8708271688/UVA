
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k;
    int n, m;
    int x, y;
    
    while(cin>>k,k!=0)
    {   
        
        cin >> n >> m;
        while (k--)
        {
            cin >> x >> y;
            if (x == n || y == m)
                cout << "divisa" << endl;
            else if (x > n && y > m)
                cout << "NE" << endl;
            else if (x < n && y > m)
                cout << "NO" << endl;
            else if (x < n && y < m)
                cout << "SO" << endl;
            else
                cout << "SE" << endl;

        }
    }
    
}

