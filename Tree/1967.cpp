#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
vector<pair<int, int>> adj[MAX + 2];
int diameter = 0;
void dfs(int cur, int pre, int val) {
  diameter = max(diameter, val);
  for (auto nxt : adj[cur]) {
    if (nxt.first == pre) continue;
    dfs(nxt.first, cur, val + nxt.second);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int p, c, v;
    cin >> p >> c >> v;
    adj[p].push_back({c, v});
    adj[c].push_back({p, v});
  }
  vector<int> leaves;
  for (int i = 1; i <= n; i++) if(adj[i].size() == 1) leaves.push_back(i);
  for (auto cur : leaves) {
    dfs(cur, 0, 0);
  }
  cout << diameter;
}