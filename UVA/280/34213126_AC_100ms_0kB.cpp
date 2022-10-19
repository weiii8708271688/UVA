#include<iostream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<list>
#include<string>
#include<deque>
#include<queue>
#include<stack>

using namespace std;

void DFS(vector <int> *G, int q, bool* ans) {
 for (int i = 0; i < G[q].size(); ++i) {
  if (!ans[G[q][i]]) {
   ans[G[q][i]] = 1;
   DFS(G, G[q][i], ans);
  }
 }
}

int main() {
 int n;
 while (cin >> n) {
  if (n == 0)
   break;
  vector <int> G[n+1];
  int v;
  while (cin >> v) {
   if (v == 0)
    break;
   int t;
   while (cin >> t) {
    if (t == 0)
     break;
    G[v].push_back(t);
   }
  }
  int n1;
  cin >> n1;
  for (int i = 0; i < n1; ++i) {
   int q;
   cin >> q;
   bool ans[100]{};
   DFS(G, q, ans);
   vector <int> ans_v;
   for (int i = 1; i < n + 1; ++i) {
    if (!ans[i])
     ans_v.push_back(i);
   }

   cout << ans_v.size();
   if (ans_v.size() != 0)
    for (auto i : ans_v)
     cout << " " << i;
   cout << endl;
  }
 }
}
