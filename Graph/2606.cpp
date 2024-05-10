#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

vector<int> adj[MAX + 5];
bool vis[MAX + 5];
int n, m, cnt;

void dfs(int x) {
  vis[x] = true;
  cnt++;
  for (auto y : adj[x]) {
    if (vis[y]) continue;
    dfs(y);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);
  cout << cnt - 1 << '\n';
}