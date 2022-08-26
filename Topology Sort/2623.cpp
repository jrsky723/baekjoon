#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
int deg[1002];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int num;
    cin >> num;
    vector<int> v(num);
    for (int i = 0; i < num; i++) cin >> v[i];
    for (int i = 0; i < num; i++) {
      for (int j = i + 1; j < num; j++) {
        adj[v[i]].push_back(v[j]);
        deg[v[j]]++;
      }
    }
  }
  vector<int> ans;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    ans.push_back(cur);
    for (int nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
  if (ans.size() == n) {
    for (auto i : ans) cout << i << '\n';
  } else
    cout << 0;
}