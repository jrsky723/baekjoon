#include <bits/stdc++.h>
using namespace std;

vector<int> adj[502];
int dist[502];
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
  fill(dist + 1, dist + 1 + n, -1);     
  // bfs
  int cnt = 0;
  queue<int> q;
  int st = 1;
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto nxt : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
      if (dist[nxt] <= 2) cnt++;
    }
  }
  cout << cnt;
} 