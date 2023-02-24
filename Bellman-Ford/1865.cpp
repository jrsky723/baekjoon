#include <bits/stdc++.h>
using namespace std;

int tc;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while (tc--) {
    int n, m, w;
    cin >> n >> m >> w;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
      int s, e, t;
      cin >> s >> e >> t;
      adj[s].push_back({e, t});
      adj[e].push_back({s, t});
    }
    for (int i = 0; i < w; i++) {
      int s, e, t;
      cin >> s >> e >> t;
      adj[s].push_back({e, -t});
    }
    int dist[n + 1];
    fill(dist, dist + n + 1, 1e9);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (auto& p : adj[j]) {
          int next = p.first;
          int d = p.second;
          if (dist[j] + d < dist[next]) {
            dist[next] = dist[j] + d;
            if (i == n) {
              cout << "YES" << '\n';
              goto END;
            }
          }
        }
      }
    }
    cout << "NO" << '\n';
  END:;
  }
}
