#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
int child[100002];
int p[100002];

int dfs(int cur, int parent) {
  for (auto nxt : adj[cur]) {
    if (nxt == parent) continue;
    p[nxt] = cur;
    child[cur]++;
    child[cur] += dfs(nxt, cur);
  }
  return child[cur];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, root, q;
  cin >> n >> root >> q;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(root, 0);
  while (q--) {
    int r;
    cin >> r;
    cout << child[r] + 1 << '\n';
  }
}