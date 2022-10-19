#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
using namespace std;
int T;
long long maxflow = 0;
long long mincost = 0;
struct edge
{
	long long h=0;
	long long x=0;
	long long y=0;
	long long cap=0;
	long long cost=0;
};
vector<edge>E[10001];
edge* parent[10001];
bool visit[10001];
long long I,J;
long long D, K;
long long depth[10001];
queue<long long >q;
void SPFA(long long s)
{
	for(long long i =0;i<=T;i++)
	{
		depth[i] = INT_MAX;
		parent[i] = nullptr;
	}
	depth[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		long long u = q.front();
		visit[u] = 0;
		q.pop();
		for (auto& e : E[u])
		{
			long long v = e.y;
			if (e.cap > 0 && depth[v] > depth[u] + e.cost)
			{
				depth[v] = depth[u] + e.cost;
				parent[v] = &e;
				if (visit[v] == 0)
				{
					visit[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
void findIj(long long h)
{
	for (long long i = 0; i <= T; i++)
	{
		for (long long j=0;j<E[i].size();j++ )
		{
			if (E[i][j].h == h)
			{
				I = i;
				J = j;
			}
		}
	}
}
bool successive(long long s, long long t)
{
	 maxflow = 0;
	 mincost = 0;
	while (true)
	{
		SPFA(s);
		if (depth[t] == INT_MAX)
		{
			return false;
		}
		long long cf = INT_MAX;
		long long v = t;
		while (v != s)
		{
			cf = min(cf, parent[v]->cap);
			v = parent[v]->x;
		}
		maxflow += cf;
		mincost += depth[t] * cf;
		if (maxflow  >= D)
		{
			return true;
		}
		v = t;
		while (v != s)
		{
			parent[v]->cap -= cf;
			findIj(parent[v]->h ^ 1);
			E[I][J].cap += cf;
			v = parent[v]->x;
		}
	}
}
int main()
{
	long long n, m;
	while (cin >> n >> m)
	{
		for (auto& ele : E)
		{
			ele.clear();
		}
		memset(visit,0,sizeof(visit));
		memset(depth, 0, sizeof(depth));
		long long count = 0;
		long long	u, v, cos;
		I = 0;
		T = n*2;
		while (m--)
		{
			cin >> u >> v >> cos;
			E[u].push_back({ count++,u,v,1,cos });
			E[v].push_back({ count++,v,u,0,-cos });
			E[v].push_back({ count++,v,u,1,cos });
			E[u].push_back({ count++,u,v,0,-cos });
		}
		cin >> D >> K;
		E[0].push_back({ count++,0,1,D,0 });
		for (long long i = 1; i <= T; i++)
		{
			for (auto& ele : E[i])
			{
				ele.cap *= K;
			}
		}
		if (successive(0, n))
		{
			cout << mincost << endl;
		}
		else
		{
			cout << "Impossible." << endl;
		}
	}
}
