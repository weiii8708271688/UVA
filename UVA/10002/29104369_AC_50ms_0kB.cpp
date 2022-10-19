#include <algorithm> 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
typedef struct pnode
{
	double x,y,d;
}point; 
point P[ 105 ];
point S[ 105 ];
point MP;
 
double crossproduct( point a, point b, point c )//ab到ac 
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
 
double dist( point a, point b )
{
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
 
point center( point *Point, int N )
{
	double sum = 0.0,s;
	point  p; p.x = p.y = 0.0;
	
	if ( N == 0 ) return p;
	if ( N == 1 ) return P[0];
	if ( N == 2 ) {
		p.x = (Point[0].x+Point[1].x)/2;
		p.y = (Point[0].y+Point[1].y)/2;
		return p;
	}
	
	for ( int i = 2 ; i < N ; ++ i ) {
		s = crossproduct( Point[0], Point[i-1], Point[i] );
		p.x += (Point[0].x+Point[i-1].x+Point[i].x)*s;
		p.y += (Point[0].y+Point[i-1].y+Point[i].y)*s;
		sum += s;
	}
	p.x /= 3*sum; p.y /= 3*sum;
	return p;
}
 
bool cmp1( point a, point b )
{
	if ( a.x == b.x ) return a.y < b.y;
	else return a.x < b.x;
}
 
bool cmp2( point a, point b )
{
	return crossproduct( P[0], a, b ) > 0;
}
 
bool cmp3( point a, point b )
{
	double cp = crossproduct( P[0], a, b );
	if ( cp == 0.0 ) {
		if ( !crossproduct( P[0], a, MP ) )
			return a.d < b.d;
		else return a.d > b.d;
	}else return cp > 0;
}
 
void Graham( int N )
{
	sort( P+0, P+N, cmp1 );
	sort( P+1, P+N, cmp2 );
	//处理共线，去掉共线的点 
	for ( int i = 1 ; i < N ; ++ i )
		P[i].d = dist( P[0], P[i] );
	MP = P[N-1];
	sort( P+1, P+N, cmp3 );
	
	int top = -1;
	if ( N > 0 ) S[++ top] = P[0];
	if ( N > 1 ) S[++ top] = P[1];
	if ( N > 2 ) {
		S[++ top] = P[2];
		for ( int i = 3 ; i < N ; ++ i ) {
			while ( crossproduct( S[top-1], S[top], P[i] ) < 0 ) -- top;
			S[++ top] = P[i];
		}
	}
	S[++ top] = P[0];
	point c = center( S, top );
	
	printf("%.3lf %.3lf\n",c.x,c.y);
}
 
int main()
{
	int  N;
	while ( scanf("%d",&N) && N > 2 ) {
		for ( int i = 0 ; i < N ; ++ i ) 
			scanf("%lf%lf",&P[i].x,&P[i].y);
		
		Graham( N );
	}
	return 0;
}