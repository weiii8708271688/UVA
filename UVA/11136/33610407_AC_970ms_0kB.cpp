#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <stdlib.h>
#define maxn 100005
using namespace std;
multiset<int>s;
int main()
{
    int n;
    while (cin>>n && n)
    {
        int m;
        long long ans=0;
        s.clear();
        multiset<int>::iterator ll,rr;
        for (int i = 0;i<n;i++)
        {
            scanf("%d",&m);
            int tmp;
            for (int j = 0;j<m;j++)
            {
                scanf("%d",&tmp);
                s.insert(tmp);
            }
            ll = s.begin();
            rr = (--s.end());

            ans += *rr-*ll;
            s.erase(rr);
            s.erase(ll);
        }
        printf("%lld\n",ans);
    }
    return 0;
}