#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef long long ll;
const ll INF = LLONG_MAX / 2;
int n, m;
vector<pair<ll, int>> adj[100005];
ll d[1000005];

void dijkstra(int st) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  fill(d + 1, d + 1 + n, INF);
  d[st] = 0;
  pq.push({ d[st], st });
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (cur.X != d[cur.Y]) continue;
    int mRem = d[cur.Y] % m;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + (m + nxt.X - mRem) % m + 1) continue;
      d[nxt.Y] = d[cur.Y] + (m + nxt.X - mRem) % m + 1;
      pq.push({ d[nxt.Y], nxt.Y });
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({ i,v });
    adj[v].push_back({ i,u });
  }
  dijkstra(1);
  cout << d[n];
}