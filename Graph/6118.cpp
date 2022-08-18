#include<bits/stdc++.h>
using namespace std;
vector<int> adj[20002];
int dist[20002];
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
  queue<int> q;
  fill(dist + 1, dist + 1 + n, -1);
  int st = 1;
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nxt : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  int mx = max_element(dist + 2, dist + 1 + n) - dist;
  int cnt = 0;
  for (int i = 2; i <= n; i++) if (dist[mx] == dist[i]) cnt++;
  cout << mx << ' ' << dist[mx] << ' ' << cnt;
}