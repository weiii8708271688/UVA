#include <iostream>
#include <vector> 
#include <stack>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
//AC
struct Edge
{
	int endPoint1;
	int endPoint2;

	Edge( int node1 = 0, int node2 = 0 )
	{
		endPoint1 = node1;
		endPoint2 = node2;
	}

	int operator!=( Edge right )
	{
		return ( endPoint1 != right.endPoint1 || endPoint2 != right.endPoint2 );
	}
};

const int N = 50005;
int d[ N ];
int low[ N ];
int parent[ N ];            // parent[ u ] is the parent if u
int numChildren;            // the number of children of the root, i.e., node 1
int dfsTime;
int numBcc;                 // the total number of biconnected components of the given graph
bool isCutPoint[ N ];       // isCutPoint[ u ] is true iff node u is a cut point
vector< int > adjList[ N ]; // the adjacency list of the given graph
set< int > bcc[ N ];        // bcc[ i ] contains all nodes in i-th biconnected component
stack< Edge > edgeStack;    // a stack of edges
long long miniNumber;       // the minimum number of escape shafts
long long numWays;          // the total number of ways in which
							// miniNumber escape shafts can be installed

// implement Tarjan's biconnected component algorithm
// put all nodes in i-th biconnected component into bcc[ i ]
void tarjanBCC( int u )
{
	d[ u ] = low[ u ] = ++dfsTime;
	for( int i = 0; i < adjList[ u ].size(); ++i ) {
		if( d[ adjList[ u ][ i ] ] == 0 ) {
			if( u == 1 )
				++numChildren;
			parent[ adjList[ u ][ i ] ] = u;
			edgeStack.push( Edge( u, adjList[ u ][ i ] ) );
			tarjanBCC( adjList[ u ][ i ] );
			if( low[ u ] > low[ adjList[ u ][ i ] ] )
				low[ u ] = low[ adjList[ u ][ i ] ];
		}
		else if( parent[ u ] != adjList[ u ][ i ] ) {
			if( d[ adjList[ u ][ i ] ] < d[ u ] )
				edgeStack.push( Edge( u, adjList[ u ][ i ] ) );
			if( low[ u ] > d[ adjList[ u ][ i ] ] )
				low[ u ] = d[ adjList[ u ][ i ] ];
		}
	}

	if( parent[ u ] != 0 ) {
		if( low[ u ] >= d[ parent[ u ] ] ) {
			if( parent[ parent[ u ] ] != 0 )
				isCutPoint[ parent[ u ] ] = true;
			set <int> tempSet;
			Edge tempEdge;
			do {
				tempEdge = edgeStack.top();
				edgeStack.pop();
				tempSet.emplace( tempEdge.endPoint1 );
				tempSet.emplace( tempEdge.endPoint2 );
			} while( tempEdge != Edge( parent[ u ], u ) );
			bcc[ numBcc++ ] = tempSet;
		}
	}
}

// computes miniNumber and numWays
void solve()
{
	miniNumber = 0;
	numWays = 1;
	for( int i = 0; i < numBcc; ++i ) {
		int count = 0;
		for( auto j : bcc[ i ] ) {
			if( isCutPoint[ j ] )
				++count;
		}
		if( count == 0 ) {
			miniNumber += 2;
			numWays *= bcc[ i ].size() * ( bcc[ i ].size() - 1 ) / 2;
		}
		else if( count == 1 ) {
			++miniNumber;
			numWays *= ( bcc[ i ].size() - 1 );
		}
	}
}

int main()
{
	int numCases = 0;
	int N;
	cin >> N;
	while( N != 0 )
	{
		int s, t, maxNodeID = 0;
		for( int i = 0; i < N; i++ )
		{
			cin >> s >> t;
			adjList[ s ].push_back( t );
			adjList[ t ].push_back( s );
			maxNodeID = max( maxNodeID, s );
			maxNodeID = max( maxNodeID, t );
		}

		memset( d, 0, sizeof( d ) );
		memset( parent, 0, sizeof( parent ) );
		memset( isCutPoint, false, sizeof( isCutPoint ) );
		dfsTime = numBcc = 0;
		numChildren = 0;
		tarjanBCC( 1 ); // put all nodes in i-th biconnected component into bcc[ i ]

		if( numChildren > 1 )
			isCutPoint[ 1 ] = true;

		solve(); // computes miniNumber and numWays

		cout << "Case " << ++numCases << ": " << miniNumber << " " << numWays << "\n";

		for( int i = 1; i <= maxNodeID; i++ )
			adjList[ i ].clear();

		for( int i = 1; i <= numBcc; i++ )
			bcc[ i ].clear();

		cin >> N;
	}

	system( "pause" );
}