#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define X first
#define Y second

vector<pair<int, int>> adj[1002];
int d[1002];
int n, m;

void dijkstra(int st) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  fill(d + 1, d + 1 + n, INF);
  d[st] = 0;
  pq.push({ d[st], st });
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({ d[nxt.Y], nxt.Y });
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({ w,v });
  }
  int a, b;
  cin >> a >> b;
  dijkstra(a);
  cout << d[b];
}