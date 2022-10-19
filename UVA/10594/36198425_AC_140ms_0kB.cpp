#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxNodeNo = 110;
const int inf = 100000000;

struct Edge
{
	int tail, head;
	int resCap;
	long long cost;
	Edge(int t, int h, int r, long long c)
		: tail(t),
		head(h),
		resCap(r),
		cost(c)
	{
	}
};

vector< Edge > edges; // vector of directed edges
//Edge edges[4 * 5005]; // array of directed edges

// outgoingEdges[ u ] stores all outgoing edges of node u
vector< int > outgoingEdges[maxNodeNo];

int nodeNum, edgeNum, dataSize, capacitySize;
vector<long long>dis;
vector<int>parent;


void addEdge(const int& start, const int& end, const int& capacity, const long long cost, int& edgeNo)
{
	edges.push_back(Edge(end, start, 0, -cost));
	outgoingEdges[start].push_back(edgeNo++);
	edges.push_back(Edge(start, end, capacity, cost));
	outgoingEdges[end].push_back(edgeNo++);
}


bool SPFA(const int& start, const int& end) //把tail當成start head當成end
{
	vector<bool>inQueue(nodeNum + 1);
	dis.assign(nodeNum + 1, inf);
	queue<int>q;
	dis[start] = 0;
	q.push(start);
	for (int u, v; q.size();)
	{
		u = q.front();
		q.pop();
		inQueue[u] = false;
		for (int e : outgoingEdges[u])
		{
			v = edges[e].tail;
			if (edges[e].resCap > 0 && dis[v] > dis[u] + edges[e].cost)
			{
				dis[v] = dis[u] + edges[e].cost;
				parent[v] = e;
				if (inQueue[v] == false)
				{
					q.push(v);
					inQueue[v] = true;
				}
			}
		}
	}

	return dis[nodeNum] != inf;
}

void MCMF(const int& start, const int& end)
{
	long long maxflow = 0, minCost = 0;
	while (SPFA(start, end))
	{
		int minCapacity = inf;
		for (int v = end; v != start; v = edges[parent[v]].head)
		{
			minCapacity = min(minCapacity, edges[parent[v]].resCap);
		}

		maxflow += minCapacity;
		minCost += minCapacity * dis[nodeNum];
		for (int v = end; v != start; v = edges[parent[v]].head)
		{
			edges[parent[v]].resCap -= minCapacity;
			edges[parent[v] ^ 1].resCap += minCapacity;
		}
	}

	if (maxflow >= dataSize)
	{
		cout << minCost << endl;
		return;
	}

	cout << "Impossible.\n";
}

int main()
{
	for (int start, end, capacity, cost, edgeNo; cin >> nodeNum >> edgeNum; edges.clear())
	{
		parent.assign(maxNodeNo, -1);
		for (addEdge(0, 1, 1, 0, edgeNo = 0); edgeNum--;)
		{
			cin >> start >> end >> cost;
			addEdge(start, end, 1, cost, edgeNo);
			addEdge(end, start, 1, cost, edgeNo);
		}

		cin >> dataSize >> capacitySize;
		edges[0].resCap = dataSize;
		for (int i = 2; i < edges.size(); i++)
		{
			edges[i].resCap *= capacitySize;
		}

		MCMF(0, nodeNum);

		for (int i = 0; i < maxNodeNo; i++)
		{
			outgoingEdges[i].clear();
		}
	}

	system("pause");
}