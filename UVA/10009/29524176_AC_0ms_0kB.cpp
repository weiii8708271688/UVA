#include <iostream>  
#include <cstdlib>  
#include <cstring>  
#include <cstdio>  
  
using namespace std;  
  
//hash  
typedef struct h_node {  
    char    name[101];  
    int     id;  
    h_node *next;  
}hnode;  
hnode* h_head[1000001];  
hnode  h_node[1001];  
  
int  h_count;  
int  h_table[9] = {3,13,31,131,313,1313,3131,13131};  
  
void hash_inital()  
{  
    h_count = 0;  
    memset( h_head, 0, sizeof(h_head) );  
}  
  
int hash_id( char* name )  
{  
    int value = 0;  
    for ( int i = 0 ; name[i] ; ++ i )  
        value = (value+name[i]*h_table[i%8])%1000000;  
      
    for ( hnode* p = h_head[value] ; p ; p = p->next )  
        if ( !strcmp( p->name, name ) )  
            return p->id;  
      
    strcpy( h_node[h_count].name, name);   
    h_node[h_count].id = h_count;  
    h_node[h_count].next = h_head[value];  
    h_head[value] = &h_node[h_count];  
      
    return h_count ++;  
}  
//end_hash  
  
//link  
typedef struct e_node {  
    int     point;  
    e_node *next;  
}enode;  
enode *e_head[1001];  
enode  e_node[2000002];  
  
int  e_count;  
  
void link_inital()  
{  
    e_count = 0;  
    memset( e_head, 0, sizeof(e_head) );  
}  
  
void link_add( int a, int b )  
{  
    e_node[e_count].point = b;  
    e_node[e_count].next = e_head[a];  
    e_head[a] = &e_node[e_count ++];  
}  
//end_link  
  
int  used[1001];  
int  frot[1001];  
int  queue[1001];  
  
void bfs( int s )  
{  
    memset( used, 0, sizeof(used) );  
      
    int move = 0,save = 0;  
    used[s] = 1;  
    frot[s] = s;  
    queue[save ++] = s;  
    while ( move < save ) {  
        int now = queue[move ++];  
        for ( enode* p = e_head[now] ; p ; p = p->next )  
            if ( !used[p->point] ) {  
                used[p->point] = 1;  
                frot[p->point] = now;  
                queue[save ++] = p->point;  
            }  
    }  
}  
  
char city1[101];  
char city2[101];  
  
void output( int s )  
{  
    if ( s != frot[s] )   
        output( frot[s] );  
    printf("%c",h_node[s].name[0]);  
}  
  
int main()  
{  
    int t,n,m,id1,id2;  
    while ( cin >> t )  
    while ( t -- ) {  
        cin >> n >> m;  
        link_inital();  
        hash_inital();  
        for ( int i = 0 ; i < n ; ++ i ) {  
            cin >> city1 >> city2;  
            id1 = hash_id( city1 );  
            id2 = hash_id( city2 );  
            link_add( id1, id2 );  
            link_add( id2, id1 );  
        }  
          
        for ( int i = 0 ; i < m ; ++ i ) {  
            cin >> city1 >> city2;  
            bfs( hash_id( city1 ) );  
            output( hash_id( city2 ) );  
            printf("\n");  
        }  
        if ( t ) printf("\n");  
    }  
}  