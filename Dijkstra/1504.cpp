#include <bits/stdc++.h>  
using namespace std;

#define X first
#define Y second

const int INF = 0x7f7f7f7f/3;
vector<pair<int, int>> adj[802];
int d[802];
int n, e, v1, v2;

void dijkstra(int st) {
  priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  fill(d + 1, d + 1 + n, INF);
  d[st] = 0;
  pq.push({ d[st], st });
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({ d[nxt.Y] , nxt.Y });
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> e;
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({ c,b });
    adj[b].push_back({ c,a });
  }
  cin >> v1 >> v2;
  int d1, d2;
  dijkstra(1);
  d1 = d[v1], d2 = d[v2];
  dijkstra(v1);
  d1 += d[v2], d2 += d[v2];
  dijkstra(n);
  d1 += d[v2], d2 += d[v1];
  int ans = min(d1, d2);
  if (ans >= INF) cout << -1;
  else cout << ans;
}