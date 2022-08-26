#include <bits/stdc++.h>
using namespace std;
map<string, int> s2i;
string i2s[1002];
vector<int> adj[1002];
vector<int> child[1002];
int deg[1002];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> i2s[i];
  sort(i2s + 1, i2s + 1 + n);
  for (int i = 1; i <= n; i++) s2i[i2s[i]] = i;
  cin >> m;
  while (m--) {
    string x, y;
    cin >> x >> y;
    adj[s2i[y]].push_back(s2i[x]);
    deg[s2i[x]]++;
  }
  vector<int> ansces;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      ansces.push_back(i);
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) {
        q.push(nxt);
        child[cur].push_back(nxt);
      }
    }
  }
  cout << ansces.size() << '\n';
  for (auto i : ansces) cout << i2s[i]<< ' ';
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << i2s[i] << ' ' << child[i].size() << ' ';
    if (child[i].size() > 1) sort(child[i].begin(), child[i].end());
    for (auto j : child[i]) cout << i2s[j] << ' ';
    cout << '\n';
  }
}