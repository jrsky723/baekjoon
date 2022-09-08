#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = LLONG_MAX;
vector<pair<int, int>> adj[10005];
ll d[22][10005];
int n, m, k;

void dijkstra(int st) {
  for (int i = 0; i <= k; i++) fill(d[i] + 1, d[i] + 1 + n, INF);
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
  d[0][st] = 0;
  pq.push({ d[0][st], 0, st });
  while (!pq.empty()) {
    ll curW;
    int curK, curN;
    tie(curW, curK, curN) = pq.top(); pq.pop();
    if (curW != d[curK][curN]) continue;
    for (auto nxtP : adj[curN]) {
      ll nxtW, nxtN;
      tie(nxtW, nxtN) = nxtP;
      if (curK < k && d[curK + 1][nxtN] > d[curK][curN]) {
        d[curK + 1][nxtN] = d[curK][curN];
        pq.push({ d[curK + 1][nxtN], curK + 1, nxtN });
      }
      if (d[curK][nxtN] > d[curK][curN] + nxtW) {
        d[curK][nxtN] = d[curK][curN] + nxtW;
        pq.push({ d[curK][nxtN], curK, nxtN });
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({ w,v });
    adj[v].push_back({ w,u });
  }
  dijkstra(1);
  ll ans = d[0][n];
  for (int i = 1; i <= k; i++) ans = min(ans, d[i][n]);
  cout << ans;
}