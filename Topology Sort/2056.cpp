#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
vector<int> adj[MAX + 2];
int deg[MAX + 2];
int t[MAX + 2];
int dist[MAX + 2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int m, v;
    cin >> t[i] >> m;
    while(m--) {
      cin >> v;
      adj[i].push_back(v);
      deg[v]++;
    }
  }
  queue<int> q;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.push(i);
      dist[i] = t[i];
    }
  }
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
      dist[nxt] = max(dist[nxt], dist[cur] + t[nxt]);
    }
  }
  cout << *max_element(dist + 1, dist + 1 + n);
}