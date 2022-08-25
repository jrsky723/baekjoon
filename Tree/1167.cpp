#include <bits/stdc++.h>
using namespace std;
const int MAX = 100'000;
vector<pair<int, int>> adj[MAX + 2];
int maxDist, maxNode;
void dfs(int cur, int prev, int dist) {
  if (dist > maxDist) {
    maxNode = cur;
    maxDist = dist;
  }
  for (auto nxt : adj[cur]) {
    if (nxt.first == prev) continue;
    dfs(nxt.first, cur, dist + nxt.second);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    while (v != -1) {
      int dist;
      cin >> dist;
      adj[u].push_back({v, dist});
      cin >> v;
    }
  }
  dfs(1, 0, 0);
  dfs(maxNode, 0, 0);
  cout << maxDist;
}