#include <bits/stdc++.h>
using namespace std;
vector<int> adj[501];
bool vis[501];

bool dfs(int cur, int parent) {
  vis[cur] = true;
  for (auto nxt : adj[cur]){
    if (nxt == parent) continue;
    if (vis[nxt]) return false;
    if (dfs(nxt, cur) == false) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 0;
  while (1) {
    int n, m, ans = 0;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    tc++;
    for (int i = 1; i <= n; i++){
      adj[i].clear();
      vis[i] = 0;
    }
    while (m--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i])
        if (dfs(i, 0)) ans++;
    }
    cout << "Case " << tc << ": ";
    if (ans > 1)
      cout << "A forest of " << ans << " trees." << '\n';
      else if (ans == 1)
        cout << "There is one tree." << '\n';
      else if (ans == 0)
        cout << "No trees." << '\n';
  }
}