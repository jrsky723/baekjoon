#include <bits/stdc++.h>
using namespace std;
int color[20005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    bool bipartite = 1;
    vector<vector<int>> adj(n + 1);
    fill(color + 1, color + 1 + n, 0);
    while (m--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }//싸이클이 존재하는가?
    for (int st = 1; st <= n; st++) {
      if(color[st]) continue;
      queue<int> q;
      color[st] = 1;
      q.push(st);
      while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
          if (color[nxt]) {
            if (color[nxt] == color[cur]) bipartite = 0;
            continue;
          }
          color[nxt] = -color[cur];
          q.push(nxt);
        }
      }
      if (!bipartite) break;
    }
    if(bipartite) cout << "YES\n";
    else cout << "NO\n";
  }
}