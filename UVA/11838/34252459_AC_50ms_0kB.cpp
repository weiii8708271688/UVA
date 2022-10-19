#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
//AC
const int maxNumNodes = 2005;
vector< int > adjList[ maxNumNodes ]; // the adjacency list of the given graph
int d[ maxNumNodes ];
int low[ maxNumNodes ];
int dfsTime;
stack< int > nodeStack;      // a stack of nodes
bool inStack[ maxNumNodes ]; // inStack[ u ] is true if and only if node u is in nodeStack
int numSCCs;                 // the numbers of strongly connected components of the given graph

// implement Tarjan's strongly component algorithm
// compute numSCCs
void tarjanSCC( int u )
{
	d[ u ] = low[ u ] = ++dfsTime;
	nodeStack.push( u );
	inStack[ u ] = true;
	for( int i = 0; i < adjList[ u ].size(); ++i ) {
		if( d[ adjList[ u ][ i ] ] == 0 ) {
			tarjanSCC( adjList[ u ][ i ] );
			if( low[ u ] > low[ adjList[ u ][ i ] ] )
				low[ u ] = low[ adjList[ u ][ i ] ];
		}
		else if( inStack[ adjList[ u ][ i ] ] ) {
			if( low[ u ] > d[ adjList[ u ][ i ] ] )
				low[ u ] = d[ adjList[ u ][ i ] ];
		}
	}

	if( low[ u ] == d[ u ] ) {
		int w;
		do {
			w = nodeStack.top();
			nodeStack.pop();
			inStack[ w ] = false;
		} while( w != u );
		++numSCCs;
	}
}

int main() {
	int n, m;
	while( cin >> n >> m ) {
		if( n == 0 && m == 0 )
			break;

		memset( d, 0, sizeof( d ) );
		dfsTime = numSCCs = 0;
		for( int i = 1; i <= n; i++ )
			adjList[ i ].clear();

		for( int i = 0, a, b, dir; i < m; ++i ) {
			cin >> a >> b >> dir;
			adjList[ a ].push_back( b );
			if( dir == 2 )
				adjList[ b ].push_back( a );
		}
		for( int i = 1; i <= n; ++i )
			if( d[ i ] == 0 )
				tarjanSCC( i );
		if( numSCCs == 1 )
			cout << 1;
		else
			cout << 0;
		cout << endl;
	}
}