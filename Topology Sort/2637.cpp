#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[102];
int info[102][102];
int deg[102];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b, num;
    cin >> a >> b >> num;
    adj[b].push_back({a, num});
    deg[a] += num;
  }
  queue<int> q;
  vector<int> basic;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      basic.push_back(i);
      q.push(i);
      info[i][i] = 1;
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto P : adj[cur]) {
      auto [nxt, num] = P;
      deg[nxt] -= num;
      for (int i : basic) info[nxt][i] += num * info[cur][i];
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
  for (int i : basic) cout << i << ' ' << info[n][i] << '\n';
}