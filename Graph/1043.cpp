#include <bits/stdc++.h>
using namespace std;
vector<int> adj[51];
vector<int> party[51];
bool vis[51];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  queue<int> q;
  while(k--) {
    int x;
    cin >> x;
    q.push(x);
    vis[x] = true;
  }
  for (int pIdx = 1; pIdx <= m; pIdx++) {
    int pN;
    cin >> pN;
    vector<int> temp(pN);
    for (int i = 0; i < pN; i++) cin >> temp[i];
    for (int i = 0; i < pN; i++) {
      for (int j = 0; j < pN; j++) {
        if (i == j) continue;
        adj[temp[i]].push_back(temp[j]);
      }
    }
    party[pIdx] = temp;
  }
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nxt : adj[cur]) {
      if (vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
  int ans = 0;
  for (int pIdx = 1; pIdx <= m; ++pIdx) {
    bool ava = 1;
    for (auto x : party[pIdx]) {
      if (vis[x]){
        ava = 0;
        break;
      }
    }
    if (ava) ans++;
  }
  cout << ans;
}