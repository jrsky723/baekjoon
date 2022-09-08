#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;

set<pair<int, int>> adj[505], revAdj[505];
vector<pair<int, int>> edge;
int d[505];
bool vis[505];
int n, m, st, en;

void dijkstra() {
  fill(d, d + n, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  d[st] = 0;
  pq.push({ d[st], st });
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (cur.X != d[cur.Y]) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.X] <= d[cur.Y] + nxt.Y) continue;
      d[nxt.X] = d[cur.Y] + nxt.Y;
      pq.push({ d[nxt.X], nxt.X });
    }
  }
}
void dfs(int cur, int dist) {
  vis[cur] = 1;
  for (auto pre : revAdj[cur]) {
    if (pre.Y + dist + d[pre.X] == d[en]) {
      edge.push_back({ pre.X, cur });
      if (!vis[pre.X]) dfs(pre.X, dist + pre.Y);
    }
  }
}

void eraseAdj() {
  for (auto p : edge) {
    auto it = adj[p.X].lower_bound({ p.Y, 0 });
    if (it != adj[p.X].end()) adj[p.X].erase(it);
  }
}
void reset() {
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
    adj[i].clear();
    revAdj[i].clear();
  }
  edge.clear();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    cin >> st >> en;
    while (m--) {
      int u, v, p;
      cin >> u >> v >> p;
      adj[u].insert({ v,p });
      revAdj[v].insert({ u,p });
    }
    dijkstra();
    if (d[en] != INF) {
      dfs(en, 0);
      eraseAdj();
      dijkstra();
      cout << (d[en] == INF ? -1 : d[en]) << '\n';
    }
    else cout << -1 << '\n';
    reset();
  }
}