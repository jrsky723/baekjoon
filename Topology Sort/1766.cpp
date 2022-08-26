#include <bits/stdc++.h>
using namespace std;
const int MAX = 32000;
set<int> adj[MAX + 2];
int deg[MAX + 2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
    deg[b]++;
  }
  set<int> s;
  for (int i = 1; i <= n; i++) if (deg[i] == 0) s.insert(i);
  while (!s.empty()) {
    int cur = *s.begin(); s.erase(s.begin());
    cout << cur << ' ';
    for (auto nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) s.insert(nxt);
    }
  }
}