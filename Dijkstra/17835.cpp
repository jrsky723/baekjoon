#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;

vector<pair<ll, int>> adj[100004];
ll d[100004];
int n, m, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[v].push_back({ w,u });
  }
  fill(d + 1, d + 1 + n, LLONG_MAX);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  while (k--) {
    int st;
    cin >> st;
    d[st] = 0;
    pq.push({ d[st],st });
  }
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({ d[nxt.Y], nxt.Y });
    }
  }
  int mx = max_element(d + 1, d + 1 + n) - d;
  cout << mx << '\n' << d[mx];
}