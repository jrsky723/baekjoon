#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = LLONG_MAX / 2;
vector<pair<int, int>> adj[1002];
ll d[1002][1002]; // 최단경로 , 경로를 지나는 간선의 갯수
int n, m, k, st, en;

void dijkstra(int st) {
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  for (int i = 1; i <= n; i++) fill(d[i], d[i] + n, INF);
  d[st][0] = 0;
  pq.push({d[st][0], st, 0});
  while (!pq.empty()) {
    int cDist, cV, cE;
    tie(cDist, cV, cE) = pq.top(); pq.pop();
    if (d[cV][cE] != cDist) continue;
    for (auto nxt : adj[cV]) {
      int w, nV;
      tie(w, nV) = nxt;
      if (d[nV][cE + 1] <= d[cV][cE] + w) continue;
      d[nV][cE + 1] = d[cV][cE] + w;
      pq.push({d[nV][cE + 1], nV, cE + 1});
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k >> st >> en;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({ w, v });
    adj[v].push_back({ w, u });
  }

  dijkstra(st);
  ll inc = 0;
  ll ans = *min_element(d[en] + 1, d[en] + n);
  cout << ans << '\n';
  while (k--) {
    int p;
    cin >> p;
    inc += p;
    ans = INF;
    for (ll i = 1; i < n; i++) 
      if (ans > d[en][i] + (inc * i)) ans = d[en][i] + (i * inc);
    cout << ans << '\n';
  }
}