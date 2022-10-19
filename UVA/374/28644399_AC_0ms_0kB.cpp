#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


long long bigmod( long long B, long long P, long long M ){
  if( P == 0 )
    return 1;
  else if( P == 1 )
    return B%M;
  else{
    long long result = bigmod( B, P/2, M );
    if( P%2 )
      return result*result*B % M;
    else
      return result*result % M;
  }
}

int main(){
  long long B, P, M;
  while( cin >> B >> P >> M )
    cout << bigmod(B,P,M) << endl;
}
