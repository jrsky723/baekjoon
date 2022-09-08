#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef long long ll;
ll INF = 1e15;
int n, m, a, b;
ll c;
vector<pair<ll, int>> adj[100005];
ll d[100005];

bool dijkstra(ll mx) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  fill(d + 1, d + 1 + n, INF);
  d[a] = 0;
  pq.push({ d[a], a });
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      if (nxt.X > mx) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({ d[nxt.Y] , nxt.Y });
    }
  }
  return d[b] > c ? 0 : 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> a >> b >> c;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({ w,v });
    adj[v].push_back({ w,u });
  }
  ll left = 1, right = c, ans = -1;
  while (left <= right) {
    ll mid = (left + right) / 2;
    if (dijkstra(mid)) right = mid - 1, ans = mid;
    else left = mid +1;
  }
  cout << ans;
}