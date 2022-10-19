#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
	int parent, rank;

	node(const int& p, const int& r)
	{
		parent = p;
		rank = r;
	}
};

struct Edge //一個邊有起點、終點、距離
{
	int start, end, dis;

	bool operator<(const Edge& right) //dis由小到大排序
	{
		return dis < right.dis;
	}

	Edge(const int& s, const int& e, const int& d)
	{
		start = s;
		end = e;
		dis = d;
	}
};

int totalDis = 0, totalAirport = 0; //當前測資中所有cost總和、建幾座機場
vector<node>point;
vector<Edge>graph;

int find_root(int start) //併查集，找root
{
	return (point[start].parent != start ? find_root(point[start].parent) : start);
}

bool union_node(const int& start, const int& end)
{
	int startRoot = find_root(start), endRoot = find_root(end); //起點和終點各找root
	if (startRoot != endRoot) //若root不同，代表不會形成環
	{
		if (point[startRoot].rank == point[endRoot].rank)
		{
			point[endRoot].parent = startRoot;
			point[startRoot].rank++;
		}
		else
		{
			(point[startRoot].rank > point[endRoot].rank) ? (point[endRoot].parent = startRoot) : (point[startRoot].parent = endRoot);
		}

		return true; //若不會形成環，則虛線可變成實線
	}

	return false;
}

void kuruskal()
{
	sort(graph.begin(), graph.end()); //先以dis由小到大排序
	for (int i = 0; i < graph.size(); i++)
	{
		if (union_node(graph[i].start, graph[i].end)) //若不會形成環
		{
			totalDis += graph[i].dis; //當前實線距離加總
		}
	}
}

int main()
{
	int testCase, t = 1; //測資
	cin >> testCase;
	for (int nodeNum, edgeNum, airportCost; testCase--; point.clear(), graph.clear())
	{
		totalDis = 0, totalAirport = 0;
		cin >> nodeNum >> edgeNum >> airportCost;
		for (int i = 0; i <= nodeNum; i++) //初始設定所有點的parent都是自己
		{
			point.push_back(node(i, 0));
		}


		for (int start, end, dis; edgeNum--;) //建圖
		{
			cin >> start >> end >> dis;
			if (dis < airportCost) //若小於機場本身的cost，則這條路可以成為虛線
			{
				graph.push_back(Edge(start, end, dis));
			}
		}

		kuruskal();
		for (int i = 1; i < point.size(); i++) //從1開始
		{
			if (point[i].parent == i) //有幾個parent == 本身，就代表有幾個subtree
			{
				totalAirport++;
			}
		}

		totalDis += totalAirport * airportCost;
		cout << "Case #" << t++ << ": " << totalDis << " " << totalAirport << endl;
	}

	system("pause");
}