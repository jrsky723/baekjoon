#include <bits/stdc++.h>
using namespace std;
set<int> child[51];
int p[51];
int leafNum[51];
int dfs(int cur, int parent) {
  if (child[cur].size() == 0) leafNum[cur] = 1;
  for (auto nxt : child[cur]) {
    leafNum[cur] += dfs(nxt, cur);
  }
  return leafNum[cur];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, root, node;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] == -1)
      root = i;
    else
      child[p[i]].insert(i);
  }
  cin >> node;
  if (root == node) {
    cout << 0; 
    return 0;
  }
  child[node].clear();
  if(p[node] != -1) child[p[node]].erase(node);
  dfs(root, -1);
  cout << leafNum[root];
}