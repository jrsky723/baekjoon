#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 * 1000 + 5, ROOT = 1;
int unused = 2;
int nxt[MX][2];
bool chk[MX];

string s;
bool dfs(int k, int cur) {
  if (k == 0) {
    chk[cur] = true;
    return true;
  }
  for (int i : {0, 1}) {
    if (chk[nxt[cur][i]]) continue;
    if (nxt[cur][i] == -1) nxt[cur][i] = unused++;
    s += ('0' + i);
    if (dfs(k - 1, nxt[cur][i])) return true;
    s.erase(prev(s.end()));
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < MX; i++) nxt[i][0] = nxt[i][1] = -1;
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<string> ans(n);
  for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
  sort(v.begin(), v.end());
  for (auto& [l, idx] : v) {
    s.clear();
    if (!dfs(l, ROOT)) {
      cout << -1 <<'\n';
      return 0;
    }
    ans[idx] = s;
  }
  cout << 1 << '\n';
  for (auto s : ans) cout << s << '\n';
}