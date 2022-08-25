#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[10005];
int p[10005];
int ans = 0;
void dfs(int cur, int en, int parent, int dist) {
  if (cur == en) ans = dist;
  for (auto nxt : adj[cur]) {
    if (parent == nxt.first) continue;
    p[nxt.first] = cur;
    dfs(nxt.first, en, cur, dist + nxt.second);
  }
}
int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);

 int n, m;
 cin >> n >> m;
 for (int i = 0; i < n - 1; i++) {
   int u, v, d;
   cin >> u >> v >> d;
   adj[u].push_back({v, d});
   adj[v].push_back({u, d});
 }
 while(m--){
  int st, en;
  cin >> st >> en;
  dfs(st, en, 0, 0);
  cout << ans << '\n';
 }
}