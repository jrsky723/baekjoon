#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
bool vis[100005];
bool chk[100005];
int connect, cycle;
void dfs(int cur, int prev) {
  vis[cur] = true;
  for (int nxt : adj[cur]) {
    if (!vis[nxt])
      dfs(nxt, cur);
    else if (nxt != prev && !chk[nxt])
      cycle++;
  }
  chk[cur] = true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
 
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i,0);
      connect++;
    }
  }
  cout << connect - 1 + cycle;
}