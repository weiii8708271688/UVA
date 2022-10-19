#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

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
    dfsTime++;
    d[u] = low[u] = dfsTime;
    nodeStack.push(u);
    inStack[u] = true;
    for(auto& v: adjList[u]) {
        if(!d[v]) {
            tarjanSCC(v);
            low[u] = min(low[u], low[v]);
            if(low[v] == d[v]) {
                int w;
                if(!nodeStack.empty()) ++numSCCs;
                //cout << numSCCs << ". ";
                do{
                    w = nodeStack.top();
                    //cout << w << " ";
                    inStack[w] = false;
                    nodeStack.pop();
                }while(w != v);
                //cout << endl;
            }
        }else if(inStack[v]) {
            low[u] = min(low[u], d[v]);
        }
    }
}


int main() {
    int n, m;
    while(cin >> n >> m) {
        if(!n && !m) break;
        memset( d, 0, sizeof( d ) );
        numSCCs = dfsTime = 0;
        while(m--){
            int a, b, bi;
            cin >> a >> b >> bi;
            adjList[a].push_back(b);
            if(bi == 2) {
                adjList[b].push_back(a);
            }
        }
        for(int i = 1 ; i <= n ; i++) {
            if(!d[i]) {
                tarjanSCC(i);
                if(!nodeStack.empty()) ++numSCCs;
                while(!nodeStack.empty()) {
                    int w = nodeStack.top();
                    //cout << w << " ";
                    nodeStack.pop();
                }
                //cout << endl;
                for(int i = 1 ; i <= n ; i++) {
                    inStack[i] = false;
                }
            }
        }

        if(numSCCs == 1) cout << 1 << endl;
        else cout << 0 << endl;

        for( int i = 1; i <= n; i++ )
         adjList[ i ].clear();
    }
}


